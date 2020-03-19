#if AMP_ENC_SPEEDUP
Void TEncCu::NonRecursive(TComDataCU*& rpcBestCU, TComDataCU*& rpcTempCU, const UInt uiDepth DEBUG_STRING_FN_DECLARE(sDebug_), PartSize eParentPartSize)
#else
Void TEncCu::NonRecursive(TComDataCU*& rpcBestCU, TComDataCU*& rpcTempCU, const UInt uiDepth)
#endif
{
    // 64x64 호출
    xCompressCU(m_ppcBestCU[0], m_ppcTempCU[0], 0 DEBUG_STRING_PASS_INTO(sDebug));
    for (UInt uiOnePart = 0; uiOnePart < 4; uiOnePart++)
    {
        //32x32 호출
        xCompressCU(m_ppcBestCU[0], m_ppcTempCU[0], 1 DEBUG_STRING_PASS_INTO(sDebug)); // 받는 인자들의 정보를 32x32에 맞는 정보들로 보내준다.
        for (UInt uiTwoPart = 0; uiTwoPart < 4; uiTwoPart++)
        {
            //16x16 호출
            xCompressCU(m_ppcBestCU[0], m_ppcTempCU[0], 2 DEBUG_STRING_PASS_INTO(sDebug)); // 16x16에 관한 정보를 보내준다
            for (UInt uiThrPart = 0; uiThrPart < 4; uiThrPart++)
            {
                //8x8 호출
                xCompressCU(m_ppcBestCU[0], m_ppcTempCU[0], 3 DEBUG_STRING_PASS_INTO(sDebug));
            }
        }
    }
    
}

// xCompressCU에 Void로 되어 있는 반환값에 return을 통해 다음 뎁스에 관한 정보들을 반환해준다. (새로운 변수 추가)
// 반환된 값은 
// TComDataCU* pcSubBestPartCU = m_ppcBestCU[uhNextDepth];
// TComDataCU* pcSubTempPartCU = m_ppcTempCU[uhNextDepth]; 이 두정보를 반환한다. 뎁스는 임의로 설정이 가능하므로 추가로 정보를 반환해주지 않는다.
//  반환된 값을 다음 뎁스의 인자로 전달한다.
// pcSubBestPartCU->initSubCU(rpcTempCU, uiPartUnitIdx, uhNextDepth, iQP); 하위 파티션 데이터 초기화 
// pcSubTempPartCU->initSubCU(rpcTempCU, uiPartUnitIdx, uhNextDepth, iQP);