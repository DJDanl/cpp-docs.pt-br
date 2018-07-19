---
title: Classe CRgn | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CRgn
- AFXWIN/CRgn
- AFXWIN/CRgn::CRgn
- AFXWIN/CRgn::CombineRgn
- AFXWIN/CRgn::CopyRgn
- AFXWIN/CRgn::CreateEllipticRgn
- AFXWIN/CRgn::CreateEllipticRgnIndirect
- AFXWIN/CRgn::CreateFromData
- AFXWIN/CRgn::CreateFromPath
- AFXWIN/CRgn::CreatePolygonRgn
- AFXWIN/CRgn::CreatePolyPolygonRgn
- AFXWIN/CRgn::CreateRectRgn
- AFXWIN/CRgn::CreateRectRgnIndirect
- AFXWIN/CRgn::CreateRoundRectRgn
- AFXWIN/CRgn::EqualRgn
- AFXWIN/CRgn::FromHandle
- AFXWIN/CRgn::GetRegionData
- AFXWIN/CRgn::GetRgnBox
- AFXWIN/CRgn::OffsetRgn
- AFXWIN/CRgn::PtInRegion
- AFXWIN/CRgn::RectInRegion
- AFXWIN/CRgn::SetRectRgn
dev_langs:
- C++
helpviewer_keywords:
- CRgn [MFC], CRgn
- CRgn [MFC], CombineRgn
- CRgn [MFC], CopyRgn
- CRgn [MFC], CreateEllipticRgn
- CRgn [MFC], CreateEllipticRgnIndirect
- CRgn [MFC], CreateFromData
- CRgn [MFC], CreateFromPath
- CRgn [MFC], CreatePolygonRgn
- CRgn [MFC], CreatePolyPolygonRgn
- CRgn [MFC], CreateRectRgn
- CRgn [MFC], CreateRectRgnIndirect
- CRgn [MFC], CreateRoundRectRgn
- CRgn [MFC], EqualRgn
- CRgn [MFC], FromHandle
- CRgn [MFC], GetRegionData
- CRgn [MFC], GetRgnBox
- CRgn [MFC], OffsetRgn
- CRgn [MFC], PtInRegion
- CRgn [MFC], RectInRegion
- CRgn [MFC], SetRectRgn
ms.assetid: d904da84-76aa-481e-8780-b09485f49e64
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 03b88f2c295ae4fa31a0afd2093251c94e1c6b79
ms.sourcegitcommit: 26fff80635bd1d51bc51899203fddfea8b29b530
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/05/2018
ms.locfileid: "37853856"
---
# <a name="crgn-class"></a>Classe CRgn
Encapsula uma região de interface (GDI) do dispositivo de gráficos Windows.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CRgn : public CGdiObject  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CRgn::CRgn](#crgn)|Constrói um objeto `CRgn`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CRgn::CombineRgn](#combinergn)|Define uma `CRgn` para que ele é equivalente a união de dois especificado do objeto `CRgn` objetos.|  
|[CRgn::CopyRgn](#copyrgn)|Define uma `CRgn` para que ele seja uma cópia de um especificado do objeto `CRgn` objeto.|  
|[CRgn::CreateEllipticRgn](#createellipticrgn)|Inicializa um `CRgn` objeto com uma região elíptico.|  
|[CRgn::CreateEllipticRgnIndirect](#createellipticrgnindirect)|Inicializa uma `CRgn` objeto com uma região elíptico definida por um [RECT](../../mfc/reference/rect-structure1.md) estrutura.|  
|[CRgn::CreateFromData](#createfromdata)|Cria uma região dos dados determinados região e a transformação.|  
|[CRgn::CreateFromPath](#createfrompath)|Cria uma região do caminho que está selecionado no contexto de determinado dispositivo.|  
|[CRgn::CreatePolygonRgn](#createpolygonrgn)|Inicializa um `CRgn` objeto com uma região em forma de polígono. O sistema fecha o polígono automaticamente, se necessário, desenhando uma linha do último vértice ao primeiro.|  
|[CRgn::CreatePolyPolygonRgn](#createpolypolygonrgn)|Inicializa um `CRgn` objeto com uma região consiste em uma série de polígonos fechados. Os polígonos podem ser não contíguos, ou eles podem se sobrepor.|  
|[CRgn::CreateRectRgn](#createrectrgn)|Inicializa um `CRgn` objeto com uma região retangular.|  
|[CRgn::CreateRectRgnIndirect](#createrectrgnindirect)|Inicializa uma `CRgn` objeto com uma região retangular definida por um [RECT](../../mfc/reference/rect-structure1.md) estrutura.|  
|[CRgn::CreateRoundRectRgn](#createroundrectrgn)|Inicializa um `CRgn` objeto com uma região retangular com cantos arredondados.|  
|[CRgn::EqualRgn](#equalrgn)|Verifica se dois `CRgn` objetos para determinar se eles são equivalentes.|  
|[CRgn::FromHandle](#fromhandle)|Retorna um ponteiro para um `CRgn` objeto quando recebe um identificador para uma região do Windows.|  
|[CRgn::GetRegionData](#getregiondata)|Preenche o buffer especificado com dados que descrevem a determinada região.|  
|[CRgn::GetRgnBox](#getrgnbox)|Recupera as coordenadas do retângulo delimitador de um `CRgn` objeto.|  
|[CRgn::OffsetRgn](#offsetrgn)|Move um `CRgn` objeto por deslocamentos especificados.|  
|[CRgn::PtInRegion](#ptinregion)|Determina se um ponto especificado está na região.|  
|[CRgn::RectInRegion](#rectinregion)|Determina se qualquer parte de um retângulo especificado está dentro dos limites da região.|  
|[CRgn::SetRectRgn](#setrectrgn)|Define o `CRgn` objeto para a região retangular especificada.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CRgn::operator HRGN](#operator_hrgn)|Retorna o identificador do Windows contido no `CRgn` objeto.|  
  
## <a name="remarks"></a>Comentários  
 Uma região é uma área elíptica ou poligonal dentro de uma janela. Para usar as regiões, você usar as funções de membro da classe `CRgn` com as funções de recorte definidas como membros da classe `CDC`.  
  
 As funções de membro de `CRgn` criar, alterar e recuperar informações sobre o objeto de região para o qual eles são chamados.  
  
 Para obter mais informações sobre como usar `CRgn`, consulte [objetos gráficos](../../mfc/graphic-objects.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CGdiObject](../../mfc/reference/cgdiobject-class.md)  
  
 `CRgn`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxwin. h  
  
##  <a name="combinergn"></a>  CRgn::CombineRgn  
 Cria uma nova região GDI, combinando duas regiões existentes.  
  
```  
int CombineRgn(
    CRgn* pRgn1,  
    CRgn* pRgn2,  
    int nCombineMode);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pRgn1*  
 Identifica uma região existente.  
  
 *pRgn2*  
 Identifica uma região existente.  
  
 *nCombineMode*  
 Especifica a operação a ser executada ao combinar as regiões de duas origens. Ele pode ser qualquer um dos seguintes valores:  
  
- RGN_AND usa a sobreposição de áreas de ambas as regiões (interseção).  
  
- RGN_COPY cria uma cópia da região 1 (identificado por *pRgn1*).  
  
- RGN_DIFF cria uma região consiste em áreas da região 1 (identificado por *pRgn1*) que não fazem parte da região 2 (identificada pelo *pRgn2*).  
  
- RGN_OR combina ambas as regiões em sua totalidade (união).  
  
- RGN_XOR combina as duas regiões, mas remove as áreas sobrepostas.  
  
### <a name="return-value"></a>Valor de retorno  
 Especifica o tipo da região resultante. Ele pode ser um dos seguintes valores:  
  
- COMPLEXREGION nova região tem bordas de sobreposição.  
  
- ERRO sem nova região criada.  
  
- NULLREGION nova região está vazia.  
  
- SIMPLEREGION nova região tem sem bordas sobrepostas.  
  
### <a name="remarks"></a>Comentários  
 As regiões são combinadas conforme especificado por *nCombineMode*.  
  
 Os dois especificados regiões são combinadas, e o identificador de região resultante é armazenado no `CRgn` objeto. Portanto, qualquer região é armazenado no `CRgn` objeto é substituído pela região combinado.  
  
 O tamanho de uma região é limitado a 64 KB de memória ou de unidades lógicas de 32.767 a 32.767, o que for menor.  
  
 Use [CopyRgn](#copyrgn) simplesmente copiar uma região para outra região.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView#144](../../mfc/codesnippet/cpp/crgn-class_1.cpp)]  
  
##  <a name="copyrgn"></a>  CRgn::CopyRgn  
 Copia a região definida pelas *pRgnSrc* para o `CRgn` objeto.  
  
```  
int CopyRgn(CRgn* pRgnSrc);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pRgnSrc*  
 Identifica uma região existente.  
  
### <a name="return-value"></a>Valor de retorno  
 Especifica o tipo da região resultante. Ele pode ser um dos seguintes valores:  
  
- COMPLEXREGION nova região tem bordas de sobreposição.  
  
- ERRO sem nova região criada.  
  
- NULLREGION nova região está vazia.  
  
- SIMPLEREGION nova região tem sem bordas sobrepostas.  
  
### <a name="remarks"></a>Comentários  
 A nova região substitui a região armazenada anteriormente no `CRgn` objeto. Essa função é um caso especial do [CombineRgn](#combinergn) função de membro.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CRgn::CreateEllipticRgn](#createellipticrgn).  
  
##  <a name="createellipticrgn"></a>  CRgn::CreateEllipticRgn  
 Cria uma região elíptica.  
  
```  
BOOL CreateEllipticRgn(
    int x1,  
    int y1,  
    int x2,  
    int y2);
```  
  
### <a name="parameters"></a>Parâmetros  
 *x1*  
 Especifica a coordenada x lógica do canto superior esquerdo do retângulo delimitador da elipse.  
  
 *y1*  
 Especifica a coordenada y lógica do canto superior esquerdo do retângulo delimitador da elipse.  
  
 *X2*  
 Especifica a coordenada x lógica do canto inferior direito do retângulo delimitador da elipse.  
  
 *y2*  
 Especifica a coordenada y lógica do canto inferior direito do retângulo delimitador da elipse.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a operação for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 A região é definida pelo retângulo delimitador especificado por *x1*, *y1*, *x2*, e *y2*. A região é armazenada no `CRgn` objeto.  
  
 O tamanho de uma região é limitado a 64 KB de memória ou de unidades lógicas de 32.767 a 32.767, o que for menor.  
  
 Quando ele tiver terminado de usar uma região criada com o `CreateEllipticRgn` função, um aplicativo deve selecionar a região fora do contexto de dispositivo e usar o `DeleteObject` função removê-lo.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView#145](../../mfc/codesnippet/cpp/crgn-class_2.cpp)]  
  
##  <a name="createellipticrgnindirect"></a>  CRgn::CreateEllipticRgnIndirect  
 Cria uma região elíptica.  
  
```  
BOOL CreateEllipticRgnIndirect(LPCRECT lpRect);
```  
  
### <a name="parameters"></a>Parâmetros  
 *lpRect*  
 Aponta para um `RECT` estrutura ou um `CRect` objeto que contém as coordenadas lógicas dos cantos superior esquerdo e direito inferior do retângulo delimitador da elipse.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a operação for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 A região é definida pela estrutura ou do objeto apontado por *lpRect* e é armazenado no `CRgn` objeto.  
  
 O tamanho de uma região é limitado a 64 KB de memória ou de unidades lógicas de 32.767 a 32.767, o que for menor.  
  
 Quando ele tiver terminado de usar uma região criada com o `CreateEllipticRgnIndirect` função, um aplicativo deve selecionar a região fora do contexto de dispositivo e usar o `DeleteObject` função removê-lo.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CRgn::CreateRectRgnIndirect](#createrectrgnindirect).  
  
##  <a name="createfromdata"></a>  CRgn::CreateFromData  
 Cria uma região dos dados determinados região e a transformação.  
  
```  
BOOL CreateFromData(
    const XFORM* lpXForm,  
    int nCount,  
    const RGNDATA* pRgnData);
```  
  
### <a name="parameters"></a>Parâmetros  
 *lpXForm*  
 Aponta para um [XFORM](../../mfc/reference/xform-structure.md) estrutura de dados que define a transformação a ser executada na região. Se esse ponteiro seja NULL, a transformação de identidade será usada.  
  
 *nCount*  
 Especifica o número de bytes apontados por *pRgnData*.  
  
 *pRgnData*  
 Aponta para um [RGNDATA](../../mfc/reference/rgndata-structure.md) estrutura de dados que contém os dados da região.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a função for bem-sucedida; caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Um aplicativo pode recuperar dados para uma região, chamando o `CRgn::GetRegionData` função.  
  
##  <a name="createfrompath"></a>  CRgn::CreateFromPath  
 Cria uma região do caminho que está selecionado no contexto de determinado dispositivo.  
  
```  
BOOL CreateFromPath(CDC* pDC);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pDC*  
 Identifica um contexto de dispositivo que contém um caminho fechado.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a função for bem-sucedida; caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O contexto de dispositivo identificado pela *pDC* parâmetro deve conter um caminho fechado. Depois de `CreateFromPath` converte um caminho em uma região, o Windows descarta o caminho fechado do contexto do dispositivo.  
  
##  <a name="createpolygonrgn"></a>  CRgn::CreatePolygonRgn  
 Cria uma região em forma de polígono.  
  
```  
BOOL CreatePolygonRgn(
    LPPOINT lpPoints,  
    int nCount,  
    int nMode);
```  
  
### <a name="parameters"></a>Parâmetros  
 *lpPoints*  
 Aponta para uma matriz de `POINT` estruturas ou uma matriz de `CPoint` objetos. Cada estrutura Especifica a coordenada x e a coordenada y de um vértice do polígono. O `POINT` estrutura tem a seguinte forma:  
  
 `typedef struct tagPOINT {`  
  
 `int x;`  
  
 `int y;`  
  
 `} POINT;`  
  
 *nCount*  
 Especifica o número de `POINT` estruturas ou `CPoint` objetos na matriz apontado por *lpPoints*.  
  
 *nMode*  
 Especifica o modo de preenchimento para a região. Esse parâmetro pode ser CONTORNO ou alternativo.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a operação for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O sistema fecha o polígono automaticamente, se necessário, desenhando uma linha do último vértice ao primeiro. A região resultante é armazenada no `CRgn` objeto.  
  
 O tamanho de uma região é limitado a 64 KB de memória ou de unidades lógicas de 32.767 a 32.767, o que for menor.  
  
 Quando o modo de preenchimento de polígono é alternativo, o sistema preenche a área entre os lados de polígono ímpares e pares em cada linha de verificação. Ou seja, o sistema preenche a área entre o lado do primeiro e segundo, entre o lado de terceiro e quarto e assim por diante.  
  
 Quando o modo de preenchimento de polígono é ENROLAMENTO, o sistema usa a direção na qual uma figura foi desenhada para determinar se uma área de preenchimento. Cada segmento de linha em um polígono é desenhado no sentido horário ou anti-horário. Sempre que uma linha imaginária extraída de uma área fechada para fora de uma figura passa por um segmento de linha no sentido horário, uma contagem é incrementada. Quando a linha passa por um segmento de linha no sentido anti-horário, a contagem é diminuída. A área é preenchida se a contagem for diferente de zero quando a linha alcança a parte externa da figura.  
  
 Quando um aplicativo tiver terminado de usar uma região criada com o `CreatePolygonRgn` função, ela deve selecionar a região fora do contexto de dispositivo e usar o `DeleteObject` função removê-lo.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView#146](../../mfc/codesnippet/cpp/crgn-class_3.cpp)]  
  
##  <a name="createpolypolygonrgn"></a>  CRgn::CreatePolyPolygonRgn  
 Cria uma região consiste em uma série de polígonos fechados.  
  
```  
BOOL CreatePolyPolygonRgn(
    LPPOINT lpPoints,  
    LPINT lpPolyCounts,  
    int nCount,  
    int nPolyFillMode);
```  
  
### <a name="parameters"></a>Parâmetros  
 *lpPoints*  
 Aponta para uma matriz de `POINT` estruturas ou uma matriz de `CPoint` objetos que define os vértices dos polígonos. Cada polígono deve ser explicitamente fechado porque o sistema não fechá-los automaticamente. Os polígonos são especificados consecutivamente. O `POINT` estrutura tem a seguinte forma:  
  
 `typedef struct tagPOINT {`  
  
 `int x;`  
  
 `int y;`  
  
 `} POINT;`  
  
 *lpPolyCounts*  
 Aponta para uma matriz de inteiros. O primeiro inteiro Especifica o número de vértices do polígono no primeiro a *lpPoints* matriz, o segundo inteiro Especifica o número de vértices no polígono segundo e assim por diante.  
  
 *nCount*  
 Especifica o número total de números inteiros na *lpPolyCounts* matriz.  
  
 *nPolyFillMode*  
 Especifica o modo de preenchimento de polígono. Esse valor pode ser CONTORNO ou alternativo.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a operação for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 A região resultante é armazenada no `CRgn` objeto.  
  
 Os polígonos podem ser não contíguos, ou eles podem se sobrepor.  
  
 O tamanho de uma região é limitado a 64 KB de memória ou de unidades lógicas de 32.767 a 32.767, o que for menor.  
  
 Quando o modo de preenchimento de polígono é alternativo, o sistema preenche a área entre os lados de polígono ímpares e pares em cada linha de verificação. Ou seja, o sistema preenche a área entre o lado do primeiro e segundo, entre o lado de terceiro e quarto e assim por diante.  
  
 Quando o modo de preenchimento de polígono é ENROLAMENTO, o sistema usa a direção na qual uma figura foi desenhada para determinar se uma área de preenchimento. Cada segmento de linha em um polígono é desenhado no sentido horário ou anti-horário. Sempre que uma linha imaginária extraída de uma área fechada para fora de uma figura passa por um segmento de linha no sentido horário, uma contagem é incrementada. Quando a linha passa por um segmento de linha no sentido anti-horário, a contagem é diminuída. A área é preenchida se a contagem for diferente de zero quando a linha alcança a parte externa da figura.  
  
 Quando um aplicativo tiver terminado de usar uma região criada com o `CreatePolyPolygonRgn` função, ela deve selecionar a região fora do contexto de dispositivo e usar o [CGDIObject::DeleteObject](../../mfc/reference/cgdiobject-class.md#deleteobject) a função de membro para removê-lo.  
  
##  <a name="createrectrgn"></a>  CRgn::CreateRectRgn  
 Cria uma região retangular que é armazenada no `CRgn` objeto.  
  
```  
BOOL CreateRectRgn(
    int x1,  
    int y1,  
    int x2,  
    int y2);
```  
  
### <a name="parameters"></a>Parâmetros  
 *x1*  
 Especifica a coordenada x lógica do canto superior esquerdo da região.  
  
 *y1*  
 Especifica a coordenada y lógica do canto superior esquerdo da região.  
  
 *X2*  
 Especifica a coordenada x lógica do canto inferior direito da região.  
  
 *y2*  
 Especifica a coordenada y lógica do canto inferior direito da região.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a operação for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O tamanho de uma região é limitado a 64 KB de memória ou de unidades lógicas de 32.767 a 32.767, o que for menor.  
  
 Quando ele tiver terminado de usar uma região criada pelo `CreateRectRgn`, um aplicativo deve usar o [CGDIObject::DeleteObject](../../mfc/reference/cgdiobject-class.md#deleteobject) a função de membro para remover a região.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView#147](../../mfc/codesnippet/cpp/crgn-class_4.cpp)]  
  
 Para obter um exemplo adicional, consulte [CRgn::CombineRgn](#combinergn).  
  
##  <a name="createrectrgnindirect"></a>  CRgn::CreateRectRgnIndirect  
 Cria uma região retangular que é armazenada no `CRgn` objeto.  
  
```  
BOOL CreateRectRgnIndirect(LPCRECT lpRect);
```  
  
### <a name="parameters"></a>Parâmetros  
 *lpRect*  
 Aponta para um `RECT` estrutura ou `CRect` objeto que contém as coordenadas lógicas dos cantos superior esquerdo e inferior direito da região. O `RECT` estrutura tem a seguinte forma:  
  
 `typedef struct tagRECT {`  
  
 `int left;`  
  
 `int top;`  
  
 `int right;`  
  
 `int bottom;`  
  
 `} RECT;`  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a operação for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O tamanho de uma região é limitado a 64 KB de memória ou de unidades lógicas de 32.767 a 32.767, o que for menor.  
  
 Quando ele tiver terminado de usar uma região criada pelo `CreateRectRgnIndirect`, um aplicativo deve usar o [CGDIObject::DeleteObject](../../mfc/reference/cgdiobject-class.md#deleteobject) a função de membro para remover a região.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView#148](../../mfc/codesnippet/cpp/crgn-class_5.cpp)]  
  
##  <a name="createroundrectrgn"></a>  CRgn::CreateRoundRectRgn  
 Cria uma região retangular com cantos arredondados que são armazenados no `CRgn` objeto.  
  
```  
BOOL CreateRoundRectRgn(
    int x1,  
    int y1,  
    int x2,  
    int y2,  
    int x3,  
    int y3);
```  
  
### <a name="parameters"></a>Parâmetros  
 *x1*  
 Especifica a coordenada x lógica do canto superior esquerdo da região.  
  
 *y1*  
 Especifica a coordenada y lógica do canto superior esquerdo da região.  
  
 *X2*  
 Especifica a coordenada x lógica do canto inferior direito da região.  
  
 *y2*  
 Especifica a coordenada y lógica do canto inferior direito da região.  
  
 *x3*  
 Especifica a largura da elipse usada para criar cantos arredondados.  
  
 *Y3*  
 Especifica a altura da elipse usada para criar cantos arredondados.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a operação for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O tamanho de uma região é limitado a 64 KB de memória ou de unidades lógicas de 32.767 a 32.767, o que for menor.  
  
 Quando um aplicativo tiver terminado de usar uma região criada com o `CreateRoundRectRgn` função, ela deve selecionar a região fora do contexto de dispositivo e usar o [CGDIObject::DeleteObject](../../mfc/reference/cgdiobject-class.md#deleteobject) a função de membro para removê-lo.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView#149](../../mfc/codesnippet/cpp/crgn-class_6.cpp)]  
  
##  <a name="crgn"></a>  CRgn::CRgn  
 Constrói um objeto `CRgn`.  
  
```  
CRgn();
```  
  
### <a name="remarks"></a>Comentários  
 O `m_hObject` membro de dados não contém uma região válida do Windows GDI até que o objeto é inicializado com um ou mais dos outros `CRgn` funções de membro.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CRgn::CreateRoundRectRgn](#createroundrectrgn).  
  
##  <a name="equalrgn"></a>  CRgn::EqualRgn  
 Determina se a determinada região é equivalente à região armazenada em do `CRgn` objeto.  
  
```  
BOOL EqualRgn(CRgn* pRgn) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 *pRgn*  
 Identifica uma região.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se as duas regiões são equivalentes; Caso contrário, 0.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView#150](../../mfc/codesnippet/cpp/crgn-class_7.cpp)]  
  
##  <a name="fromhandle"></a>  CRgn::FromHandle  
 Retorna um ponteiro para um `CRgn` objeto quando recebe um identificador para uma região do Windows.  
  
```  
static CRgn* PASCAL FromHandle(HRGN hRgn);
```  
  
### <a name="parameters"></a>Parâmetros  
 *hRgn*  
 Especifica um identificador para uma região do Windows.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para um `CRgn` objeto. Se a função não for bem-sucedida, o valor retornado é NULL.  
  
### <a name="remarks"></a>Comentários  
 Se um `CRgn` objeto já não está anexado ao identificador, um temporário `CRgn` objeto é criado e anexado. Esse temporário `CRgn` objeto é válido somente até a próxima vez que o aplicativo tem tempo ocioso em seu loop de eventos, em que ponto o gráfico temporário todos os objetos são excluídos. Outra maneira de dizer isso é que o objeto temporário só é válido durante o processamento de mensagem em uma janela.  
  
##  <a name="getregiondata"></a>  CRgn::GetRegionData  
 Preenche o buffer especificado com dados que descrevem a região.  
  
```  
int GetRegionData(
    LPRGNDATA lpRgnData,  
    int nCount) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 *lpRgnData*  
 Aponta para um [RGNDATA](../../mfc/reference/rgndata-structure.md) estrutura de dados que recebe as informações. Se esse parâmetro for NULL, o valor de retorno contém o número de bytes necessários para os dados da região.  
  
 *nCount*  
 Especifica o tamanho, em bytes, do *lpRgnData* buffer.  
  
### <a name="return-value"></a>Valor de retorno  
 Se a função tiver êxito e *nCount* Especifica um número adequado de bytes, o valor retornado é sempre *nCount*. Se a função falhar, ou se *nCount* Especifica menor que o número adequado de bytes, o valor retornado será 0 (erro).  
  
### <a name="remarks"></a>Comentários  
 Esses dados incluem as dimensões dos retângulos que formam a região. Essa função é usada em conjunto com o `CRgn::CreateFromData` função.  
  
##  <a name="getrgnbox"></a>  CRgn::GetRgnBox  
 Recupera as coordenadas do retângulo delimitador do `CRgn` objeto.  
  
```  
int GetRgnBox(LPRECT lpRect) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 *lpRect*  
 Aponta para um `RECT` estrutura ou `CRect` objeto para receber as coordenadas do retângulo delimitador. O `RECT` estrutura tem a seguinte forma:  
  
 `typedef struct tagRECT {`  
  
 `int left;`  
  
 `int top;`  
  
 `int right;`  
  
 `int bottom;`  
  
 `} RECT;`  
  
### <a name="return-value"></a>Valor de retorno  
 Especifica o tipo da região. Ele pode ser qualquer um dos seguintes valores:  
  
- Região de COMPLEXREGION tem bordas de sobreposição.  
  
- Região NULLREGION está vazia.  
  
- Erro `CRgn` objeto não especifica uma região válida.  
  
- Região de SIMPLEREGION tem sem bordas sobrepostas.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CRgn::CreatePolygonRgn](#createpolygonrgn).  
  
##  <a name="offsetrgn"></a>  CRgn::OffsetRgn  
 Move a região armazenada em do `CRgn` objeto por deslocamentos especificados.  
  
```  
int OffsetRgn(
    int x,  
    int y);  
  
int OffsetRgn(POINT point);
```  
  
### <a name="parameters"></a>Parâmetros  
 *x*  
 Especifica o número de unidades para mover para a esquerda ou direita.  
  
 *y*  
 Especifica o número de unidades para mover para cima ou para baixo.  
  
 *ponto*  
 A coordenada x do *aponte* Especifica o número de unidades para mover para a esquerda ou direita. A coordenada y do *aponte* Especifica o número de unidades para mover para cima ou para baixo. O *aponte* parâmetro pode ser um `POINT` estrutura ou um `CPoint` objeto.  
  
### <a name="return-value"></a>Valor de retorno  
 Tipo da nova região. Ele pode ser qualquer um dos seguintes valores:  
  
- Região de COMPLEXREGION tem bordas de sobreposição.  
  
- Erro ao identificador de região não é válido.  
  
- Região NULLREGION está vazia.  
  
- Região de SIMPLEREGION tem sem bordas sobrepostas.  
  
### <a name="remarks"></a>Comentários  
 A função move a região *x* unidades no eixo e *y* unidades no eixo y.  
  
 Os valores de coordenada de uma região devem ser menor ou igual a 32.767 e maior ou igual a -32.768. O *x* e *y* parâmetros devem ser escolhidos cuidadosamente para evitar que as coordenadas da região inválido.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CRgn::CreateEllipticRgn](#createellipticrgn).  
  
##  <a name="operator_hrgn"></a>  CRgn::operator HRGN  
 Use este operador para obter o identificador do Windows GDI anexado do `CRgn` objeto.  
  
```  
operator HRGN() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Se for bem-sucedido, um identificador para o objeto de GDI do Windows representado pelo `CRgn` objeto; caso contrário, nulo.  
  
### <a name="remarks"></a>Comentários  
 Esse operador é um operador de conversão, que dá suporte ao uso direto de um objeto HRGN.  
  
 Para obter mais informações sobre como usar objetos gráficos, consulte o artigo [gráfico de objetos](http://msdn.microsoft.com/library/windows/desktop/dd144962) no SDK do Windows.  
  
##  <a name="ptinregion"></a>  CRgn::PtInRegion  
 Verifica se o ponto fornecido por *x* e *y* está na região armazenado no `CRgn` objeto.  
  
```  
BOOL PtInRegion(
    int x,  
    int y) const;  
  
BOOL PtInRegion(POINT point) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 *x*  
 Especifica a coordenada x lógica do ponto a ser testado.  
  
 *y*  
 Especifica a coordenada y lógica do ponto a ser testado.  
  
 *ponto*  
 As coordenadas x e y do *aponte* especificar as coordenadas x e y do ponto a testar o valor de. O *aponte* parâmetro pode ser um `POINT` estrutura ou um `CPoint` objeto.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o ponto está na região. Caso contrário, 0.  
  
##  <a name="rectinregion"></a>  CRgn::RectInRegion  
 Determina se qualquer parte do retângulo especificado por *lpRect* está dentro dos limites da região armazenadas em do `CRgn` objeto.  
  
```  
BOOL RectInRegion(LPCRECT lpRect) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 *lpRect*  
 Aponta para um `RECT` estrutura ou `CRect` objeto. O `RECT` estrutura tem a seguinte forma:  
  
 `typedef struct tagRECT {`  
  
 `int left;`  
  
 `int top;`  
  
 `int right;`  
  
 `int bottom;`  
  
 `} RECT;`  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se qualquer parte do retângulo especificado está dentro dos limites de região. Caso contrário, 0.  
  
##  <a name="setrectrgn"></a>  CRgn::SetRectRgn  
 Cria uma região retangular.  
  
```  
void SetRectRgn(
    int x1,  
    int y1,  
    int x2,  
    int y2);  
  
void SetRectRgn(LPCRECT lpRect);
```  
  
### <a name="parameters"></a>Parâmetros  
 *x1*  
 Especifica a coordenada x do canto superior esquerdo da região retangular.  
  
 *y1*  
 Especifica a coordenada y do canto superior esquerdo da região retangular.  
  
 *X2*  
 Especifica a coordenada x do canto inferior direito da região retangular.  
  
 *y2*  
 Especifica a coordenada y do canto inferior direito da região retangular.  
  
 *lpRect*  
 Especifica a região retangular. Pode ser um ponteiro para um `RECT` estrutura ou um `CRect` objeto.  
  
### <a name="remarks"></a>Comentários  
 Diferentemente [CreateRectRgn](#createrectrgn), no entanto, ele não alocará nenhuma memória adicional do heap do aplicativo local do Windows. Em vez disso, ele usa o espaço alocado para a região armazenadas em do `CRgn` objeto. Isso significa que o `CRgn` objeto já deve ter sido inicializado com uma região válida do Windows antes de chamar `SetRectRgn`. Os pontos de fornecido pelo *x1*, *y1*, *x2*, e *y2* especificar o tamanho mínimo do que o espaço alocado.  
  
 Use essa função em vez do `CreateRectRgn` a função de membro para evitar chamadas para o Gerenciador de memória local.  
  
## <a name="see-also"></a>Consulte também  
 [Classe CWnd](../../mfc/reference/cwnd-class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)



