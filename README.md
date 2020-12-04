# HM_16.20

HEVC 코덱인 HM의 CU BlockStructure 구조에 대한 분석과 연습

HEVC의 CU BlockStructure는 Recursive구조를 가지고 있다.
이 구조를 풀어서 Recursive한 구조를 Non-Recursive구조로 변경한다.

참고 소스코드 위치
  TAppEncoder->xCompressCU
