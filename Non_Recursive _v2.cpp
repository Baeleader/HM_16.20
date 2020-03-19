#if AMP_ENC_SPEEDUP
Void TEncCu::NonRecursive(TComDataCU*& rpcBestCU, TComDataCU*& rpcTempCU, const UInt uiDepth DEBUG_STRING_FN_DECLARE(sDebug_), PartSize eParentPartSize)
#else
Void TEncCu::NonRecursive(TComDataCU*& rpcBestCU, TComDataCU*& rpcTempCU, const UInt uiDepth)
#endif
{
    // 64x64 ȣ��
    xCompressCU(m_ppcBestCU[0], m_ppcTempCU[0], 0 DEBUG_STRING_PASS_INTO(sDebug));
    for (UInt uiOnePart = 0; uiOnePart < 4; uiOnePart++)
    {
        //32x32 ȣ��
        xCompressCU(m_ppcBestCU[0], m_ppcTempCU[0], 1 DEBUG_STRING_PASS_INTO(sDebug)); // �޴� ���ڵ��� ������ 32x32�� �´� ������� �����ش�.
        for (UInt uiTwoPart = 0; uiTwoPart < 4; uiTwoPart++)
        {
            //16x16 ȣ��
            xCompressCU(m_ppcBestCU[0], m_ppcTempCU[0], 2 DEBUG_STRING_PASS_INTO(sDebug)); // 16x16�� ���� ������ �����ش�
            for (UInt uiThrPart = 0; uiThrPart < 4; uiThrPart++)
            {
                //8x8 ȣ��
                xCompressCU(m_ppcBestCU[0], m_ppcTempCU[0], 3 DEBUG_STRING_PASS_INTO(sDebug));
            }
        }
    }
    
}

// xCompressCU�� Void�� �Ǿ� �ִ� ��ȯ���� return�� ���� ���� ������ ���� �������� ��ȯ���ش�. (���ο� ���� �߰�)
// ��ȯ�� ���� 
// TComDataCU* pcSubBestPartCU = m_ppcBestCU[uhNextDepth];
// TComDataCU* pcSubTempPartCU = m_ppcTempCU[uhNextDepth]; �� �������� ��ȯ�Ѵ�. ������ ���Ƿ� ������ �����ϹǷ� �߰��� ������ ��ȯ������ �ʴ´�.
//  ��ȯ�� ���� ���� ������ ���ڷ� �����Ѵ�.
// pcSubBestPartCU->initSubCU(rpcTempCU, uiPartUnitIdx, uhNextDepth, iQP); ���� ��Ƽ�� ������ �ʱ�ȭ 
// pcSubTempPartCU->initSubCU(rpcTempCU, uiPartUnitIdx, uhNextDepth, iQP);