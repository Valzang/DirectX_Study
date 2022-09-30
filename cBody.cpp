#include "cBody.h"

cBody::cBody()
{
}

cBody::~cBody()
{
}

void cBody::SetUp()
{
	cCubeNode::SetUp(); // Á¤À°¸éÃ¼ ¸¸µê

	// ÅØ½ºÃÄ ÁÂÇ¥°ª ¼¼ÆÃ >>
    {
        m_vecVertex[0].texture.x = (float)32 / 64;   m_vecVertex[0].texture.y = (float)32 / 32;
        m_vecVertex[1].texture.x = (float)32 / 64;   m_vecVertex[1].texture.y = (float)20 / 32;
        m_vecVertex[2].texture.x = (float)40 / 64;   m_vecVertex[2].texture.y = (float)20 / 32;    //¾Õ¸é À­»ï°¢ 
                                                                     //0,1,2

        m_vecVertex[3].texture.x = (float)32 / 64;   m_vecVertex[3].texture.y = (float)32 / 32;
        m_vecVertex[4].texture.x = (float)40 / 64;   m_vecVertex[4].texture.y = (float)20 / 32;
        m_vecVertex[5].texture.x = (float)40 / 64;   m_vecVertex[5].texture.y = (float)32 / 32;    //¾Õ¸é ¾Æ·§»ï°¢
                                                                     //0,2,3

        m_vecVertex[6].texture.x = (float)28 / 64;   m_vecVertex[6].texture.y = (float)32 / 32;
        m_vecVertex[7].texture.x = (float)20 / 64;   m_vecVertex[7].texture.y = (float)20 / 32;
        m_vecVertex[8].texture.x = (float)28 / 64;   m_vecVertex[8].texture.y = (float)20 / 32;    //µÞ¸é À­»ï°¢
                                                                     //4,6,5

        m_vecVertex[9].texture.x = (float)28 / 64;   m_vecVertex[9].texture.y = (float)32 / 32;
        m_vecVertex[10].texture.x = (float)20 / 64;   m_vecVertex[10].texture.y = (float)32 / 32;
        m_vecVertex[11].texture.x = (float)20 / 64;   m_vecVertex[11].texture.y = (float)20 / 32;    //µÞ¸é ¾Æ·§»ï°¢
                                                                     //4,7,6

        m_vecVertex[12].texture.x = (float)28 / 64;   m_vecVertex[12].texture.y = (float)32 / 32;
        m_vecVertex[13].texture.x = (float)28 / 64;   m_vecVertex[13].texture.y = (float)20 / 32;
        m_vecVertex[14].texture.x = (float)32 / 64;   m_vecVertex[14].texture.y = (float)20 / 32;    //¿ÞÂÊ¸é À­»ï°¢
                                                                     //4,5,1

        m_vecVertex[15].texture.x = (float)28 / 64;   m_vecVertex[15].texture.y = (float)32 / 32;
        m_vecVertex[16].texture.x = (float)32 / 64;   m_vecVertex[16].texture.y = (float)20 / 32;
        m_vecVertex[17].texture.x = (float)32 / 64;   m_vecVertex[17].texture.y = (float)32 / 32;    //¿ÞÂÊ¸é ¾Æ·§»ï°¢
                                                                     //4,1,0

        m_vecVertex[18].texture.x = (float)16 / 64;   m_vecVertex[18].texture.y = (float)32 / 32;
        m_vecVertex[19].texture.x = (float)16 / 64;   m_vecVertex[19].texture.y = (float)20 / 32;
        m_vecVertex[20].texture.x = (float)20 / 64;   m_vecVertex[20].texture.y = (float)20 / 32;    //¿À¸¥¸é À­»ï°¢
                                                                     //3,2,6

        m_vecVertex[21].texture.x = (float)16 / 64;   m_vecVertex[21].texture.y = (float)32 / 32;
        m_vecVertex[22].texture.x = (float)20 / 64;   m_vecVertex[22].texture.y = (float)20 / 32;
        m_vecVertex[23].texture.x = (float)20 / 64;   m_vecVertex[23].texture.y = (float)32 / 32;    //¿À¸¥¸é ¾Æ·§»ï°¢
                                                                     //3,6,7

        m_vecVertex[24].texture.x = (float)28 / 64;   m_vecVertex[24].texture.y = (float)16 / 32;
        m_vecVertex[25].texture.x = (float)28 / 64;   m_vecVertex[25].texture.y = (float)20 / 32;
        m_vecVertex[26].texture.x = (float)20 / 64;   m_vecVertex[26].texture.y = (float)20 / 32;    //À­¸é À­»ï°¢
                                                                     //1,5,6

        m_vecVertex[27].texture.x = (float)28 / 64;   m_vecVertex[27].texture.y = (float)16 / 32;
        m_vecVertex[28].texture.x = (float)20 / 64;   m_vecVertex[28].texture.y = (float)20 / 32;
        m_vecVertex[29].texture.x = (float)20 / 64;   m_vecVertex[29].texture.y = (float)16 / 32;    //À­¸é ¾Æ·§»ï°¢
                                                                     //1,6,2

        m_vecVertex[30].texture.x = (float)28 / 64;   m_vecVertex[30].texture.y = (float)16 / 32;
        m_vecVertex[31].texture.x = (float)28 / 64;   m_vecVertex[31].texture.y = (float)20 / 32;
        m_vecVertex[32].texture.x = (float)36 / 64;   m_vecVertex[32].texture.y = (float)20 / 32;    //¾Æ·§¸é À­»ï°¢
                                                                     //4,0,3

        m_vecVertex[33].texture.x = (float)28 / 64;   m_vecVertex[33].texture.y = (float)16 / 32;
        m_vecVertex[34].texture.x = (float)36 / 64;   m_vecVertex[34].texture.y = (float)20 / 32;
        m_vecVertex[35].texture.x = (float)36 / 64;   m_vecVertex[35].texture.y = (float)20 / 32;    //¾Æ·§¸é ¾Æ·§»ï°¢
    }
	//

	D3DXMATRIXA16 matS, mat, matT;
	D3DXMatrixScaling(&matS, 0.4f, 0.6f, 0.2f);
	D3DXMatrixTranslation(&matT, 0.0f, 0.0f, 0.0f);
	
	mat = matS * matT;

	for (UINT i = 0; i < m_vecVertex.size(); ++i)
	{
		D3DXVec3TransformCoord(&m_vecVertex[i].pos, &m_vecVertex[i].pos, &mat);
	}

}
