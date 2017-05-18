---
title: Classe CRgn | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
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
- HRGN
- CRgn class
- regions, MFC
ms.assetid: d904da84-76aa-481e-8780-b09485f49e64
caps.latest.revision: 23
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3f91eafaf3b5d5c1b8f96b010206d699f666e224
ms.openlocfilehash: 3aa69aa3947409b5b3d96a9da92f5d4549eebbb4
ms.contentlocale: pt-br
ms.lasthandoff: 04/01/2017

---
# <a name="crgn-class"></a>Classe CRgn
Encapsula uma região do Windows gráficos dispositivo GDI (interface).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CRgn : public CGdiObject  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CRgn::CRgn](#crgn)|Constrói um objeto `CRgn`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CRgn::CombineRgn](#combinergn)|Define uma `CRgn` para que seja equivalente a união de dois especificado do objeto `CRgn` objetos.|  
|[CRgn::CopyRgn](#copyrgn)|Define uma `CRgn` para que seja uma cópia de um especificado do objeto `CRgn` objeto.|  
|[CRgn::CreateEllipticRgn](#createellipticrgn)|Inicializa uma `CRgn` objeto com uma região elíptico.|  
|[CRgn::CreateEllipticRgnIndirect](#createellipticrgnindirect)|Inicializa um `CRgn` objeto com uma região elíptico definida por um [RECT](../../mfc/reference/rect-structure1.md) estrutura.|  
|[CRgn::CreateFromData](#createfromdata)|Cria uma região de dados determinados de região e transformação.|  
|[CRgn::CreateFromPath](#createfrompath)|Cria uma região do caminho que está selecionado no contexto de determinado dispositivo.|  
|[CRgn::CreatePolygonRgn](#createpolygonrgn)|Inicializa uma `CRgn` objeto com uma região poligonal. O sistema fecha o polígono automaticamente, se necessário, ao desenhar uma linha do último vértice para o primeiro.|  
|[CRgn::CreatePolyPolygonRgn](#createpolypolygonrgn)|Inicializa uma `CRgn` objeto com uma região consiste em uma série de polígonos fechados. Os polígonos podem estar separados, ou eles podem se sobrepor.|  
|[CRgn::CreateRectRgn](#createrectrgn)|Inicializa uma `CRgn` objeto com uma área retangular.|  
|[CRgn::CreateRectRgnIndirect](#createrectrgnindirect)|Inicializa um `CRgn` objeto com uma região retangular definida por um [RECT](../../mfc/reference/rect-structure1.md) estrutura.|  
|[CRgn::CreateRoundRectRgn](#createroundrectrgn)|Inicializa uma `CRgn` objeto com uma área retangular com cantos arredondados.|  
|[CRgn::EqualRgn](#equalrgn)|Verifica se duas `CRgn` objetos para determinar se eles são equivalentes.|  
|[CRgn::FromHandle](#fromhandle)|Retorna um ponteiro para um `CRgn` objeto quando é fornecido um identificador para uma região do Windows.|  
|[CRgn::GetRegionData](#getregiondata)|Preenche o buffer especificado com dados que descrevem a determinada região.|  
|[CRgn::GetRgnBox](#getrgnbox)|Recupera as coordenadas do retângulo delimitador de um `CRgn` objeto.|  
|[CRgn::OffsetRgn](#offsetrgn)|Move um `CRgn` objeto pelos deslocamentos especificados.|  
|[CRgn::PtInRegion](#ptinregion)|Determina se um ponto especificado está na região.|  
|[CRgn::RectInRegion](#rectinregion)|Determina se qualquer parte de um retângulo especificado está dentro dos limites da região.|  
|[CRgn::SetRectRgn](#setrectrgn)|Define o `CRgn` objeto para a região retangular especificada.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CRgn::operator HRGN](#operator_hrgn)|Retorna o identificador contido no `CRgn` objeto.|  
  
## <a name="remarks"></a>Comentários  
 Uma região é uma área elíptica ou poligonal dentro de uma janela. Para usar regiões, você use as funções de membro da classe `CRgn` com as funções de recorte definidas como membros da classe `CDC`.  
  
 As funções de membro de `CRgn` criar, alterar e recuperar informações sobre o objeto de região para a qual eles são chamados.  
  
 Para obter mais informações sobre como usar `CRgn`, consulte [objetos gráficos](../../mfc/graphic-objects.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CGdiObject](../../mfc/reference/cgdiobject-class.md)  
  
 `CRgn`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxwin.h  
  
##  <a name="combinergn"></a>CRgn::CombineRgn  
 Cria uma nova região GDI combinando duas regiões existentes.  
  
```  
int CombineRgn(
    CRgn* pRgn1,  
    CRgn* pRgn2,  
    int nCombineMode);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pRgn1`  
 Identifica uma região existente.  
  
 `pRgn2`  
 Identifica uma região existente.  
  
 `nCombineMode`  
 Especifica a operação a ser executada ao combinar as regiões de origem de dois. Ele pode ser qualquer um dos seguintes valores:  
  
- **RGN_AND** usa áreas de sobreposição das duas regiões (interseção).  
  
- **RGN_COPY** cria uma cópia da região 1 (identificado por `pRgn1`).  
  
- **RGN_DIFF** cria uma região consiste em áreas de região 1 (identificado por `pRgn1`) que não fazem parte da região 2 (identificado por `pRgn2`).  
  
- **RGN_OR** combina as duas regiões em sua totalidade (união).  
  
- **RGN_XOR** combina duas regiões, mas remove as áreas de sobreposição.  
  
### <a name="return-value"></a>Valor de retorno  
 Especifica o tipo da região de dados resultante. Pode ser um dos seguintes valores:  
  
- **COMPLEXREGION** nova região tem bordas de sobreposição.  
  
- **Erro** nenhuma região novo criado.  
  
- **NULLREGION** nova região está vazia.  
  
- **SIMPLEREGION** nova região tem sem bordas sobrepostas.  
  
### <a name="remarks"></a>Comentários  
 As regiões são combinadas conforme especificado por `nCombineMode`.  
  
 Os dois especificados regiões são combinadas e o identificador de região resultante é armazenado no `CRgn` objeto. Portanto, qualquer região é armazenado no `CRgn` objeto é substituído pela região combinado.  
  
 O tamanho de uma região é limitado a 64 KB de memória ou de unidades lógicas de 32.767 a 32.767, o que for menor.  
  
 Use [CopyRgn](#copyrgn) simplesmente copiar uma região para outra região.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView #144](../../mfc/codesnippet/cpp/crgn-class_1.cpp)]  
  
##  <a name="copyrgn"></a>CRgn::CopyRgn  
 Copia a região definida pelo `pRgnSrc` para o `CRgn` objeto.  
  
```  
int CopyRgn(CRgn* pRgnSrc);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pRgnSrc`  
 Identifica uma região existente.  
  
### <a name="return-value"></a>Valor de retorno  
 Especifica o tipo da região de dados resultante. Pode ser um dos seguintes valores:  
  
- **COMPLEXREGION** nova região tem bordas de sobreposição.  
  
- **Erro** nenhuma região novo criado.  
  
- **NULLREGION** nova região está vazia.  
  
- **SIMPLEREGION** nova região tem sem bordas sobrepostas.  
  
### <a name="remarks"></a>Comentários  
 A nova região substitui a região armazenada anteriormente no `CRgn` objeto. Essa função é um caso especial do [CombineRgn](#combinergn) função de membro.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para [CRgn::CreateEllipticRgn](#createellipticrgn).  
  
##  <a name="createellipticrgn"></a>CRgn::CreateEllipticRgn  
 Cria uma região elíptica.  
  
```  
BOOL CreateEllipticRgn(
    int x1,  
    int y1,  
    int x2,  
    int y2);
```  
  
### <a name="parameters"></a>Parâmetros  
 `x1`  
 Especifica a coordenada x lógica do canto superior esquerdo do retângulo delimitador da elipse.  
  
 `y1`  
 Especifica a coordenada y lógica do canto superior esquerdo do retângulo delimitador da elipse.  
  
 `x2`  
 Especifica a coordenada x lógica do canto inferior direito do retângulo delimitador da elipse.  
  
 `y2`  
 Especifica a coordenada y lógica do canto inferior direito do retângulo delimitador da elipse.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a operação foi bem-sucedida. Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 A região é definida pelo retângulo delimitador especificado por `x1`, `y1`, `x2`, e `y2`. A região é armazenada no `CRgn` objeto.  
  
 O tamanho de uma região é limitado a 64 KB de memória ou de unidades lógicas de 32.767 a 32.767, o que for menor.  
  
 Quando terminou de usar uma região criada com o `CreateEllipticRgn` função, um aplicativo deve selecionar a região fora do contexto de dispositivo e use o `DeleteObject` função removê-lo.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView #145](../../mfc/codesnippet/cpp/crgn-class_2.cpp)]  
  
##  <a name="createellipticrgnindirect"></a>CRgn::CreateEllipticRgnIndirect  
 Cria uma região elíptica.  
  
```  
BOOL CreateEllipticRgnIndirect(LPCRECT lpRect);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpRect`  
 Aponta para um `RECT` estrutura ou um `CRect` objeto que contém as coordenadas lógicas dos cantos superior esquerdo e direito inferior do retângulo delimitador da elipse.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a operação foi bem-sucedida. Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 A região é definida, a estrutura ou o objeto apontado pelo `lpRect` e é armazenado no `CRgn` objeto.  
  
 O tamanho de uma região é limitado a 64 KB de memória ou de unidades lógicas de 32.767 a 32.767, o que for menor.  
  
 Quando terminou de usar uma região criada com o `CreateEllipticRgnIndirect` função, um aplicativo deve selecionar a região fora do contexto de dispositivo e use o `DeleteObject` função removê-lo.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para [CRgn::CreateRectRgnIndirect](#createrectrgnindirect).  
  
##  <a name="createfromdata"></a>CRgn::CreateFromData  
 Cria uma região de dados determinados de região e transformação.  
  
```  
BOOL CreateFromData(
    const XFORM* lpXForm,  
    int nCount,  
    const RGNDATA* pRgnData);
```  
  
### <a name="parameters"></a>Parâmetros  
 *lpXForm*  
 Aponta para um [XFORM](../../mfc/reference/xform-structure.md) estrutura de dados que define a transformação a ser executada na região. Se esse ponteiro for **nulo**, a transformação de identidade é usada.  
  
 `nCount`  
 Especifica o número de bytes apontada pelo `pRgnData`.  
  
 `pRgnData`  
 Aponta para um [RGNDATA](../../mfc/reference/rgndata-structure.md) estrutura de dados que contém os dados da região.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a função for bem-sucedida; caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Um aplicativo pode recuperar dados para uma região chamando o `CRgn::GetRegionData` função.  
  
##  <a name="createfrompath"></a>CRgn::CreateFromPath  
 Cria uma região do caminho que está selecionado no contexto de determinado dispositivo.  
  
```  
BOOL CreateFromPath(CDC* pDC);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDC`  
 Identifica um contexto de dispositivo que contém um caminho fechado.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a função for bem-sucedida; caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O contexto de dispositivo identificado pelo `pDC` parâmetro deve conter um caminho fechado. Depois de `CreateFromPath` converte um caminho em uma região, o Windows descarta o caminho fechado do contexto de dispositivo.  
  
##  <a name="createpolygonrgn"></a>CRgn::CreatePolygonRgn  
 Cria uma região poligonal.  
  
```  
BOOL CreatePolygonRgn(
    LPPOINT lpPoints,  
    int nCount,  
    int nMode);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpPoints`  
 Aponta para uma matriz de **ponto** estruturas ou uma matriz de `CPoint` objetos. Cada estrutura Especifica a coordenada x e y de um vértice do polígono. O **ponto** estrutura tem a seguinte forma:  
  
 `typedef struct tagPOINT {`  
  
 `int x;`  
  
 `int y;`  
  
 `} POINT;`  
  
 `nCount`  
 Especifica o número de **ponto** estruturas ou `CPoint` objetos na matriz apontada pelo `lpPoints`.  
  
 `nMode`  
 Especifica o modo de preenchimento para a região. Esse parâmetro pode ser **alternativo** ou **CONTORNO**.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a operação foi bem-sucedida. Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O sistema fecha o polígono automaticamente, se necessário, ao desenhar uma linha do último vértice para o primeiro. A região resultante é armazenada no `CRgn` objeto.  
  
 O tamanho de uma região é limitado a 64 KB de memória ou de unidades lógicas de 32.767 a 32.767, o que for menor.  
  
 Quando o modo de preenchimento de polígono é **alternativo**, o sistema preenche a área entre os lados do polígono ímpares e pares em cada linha de verificação. Ou seja, o sistema preenche a área entre o primeiro e o segundo lado, entre o terceiro e quarto lado e assim por diante.  
  
 Quando o modo de preenchimento de polígono é **CONTORNO**, o sistema usa a direção na qual uma figura foi desenhada para determinar se uma área de preenchimento. Cada segmento de linha em um polígono é desenhado no sentido horário ou sentido anti-horário. Sempre que uma linha imaginária extraída de uma área fechada para fora de uma figura passa por um segmento de linha no sentido horário, uma contagem é incrementada. Quando a linha passa por um segmento de linha no sentido anti-horário, a contagem é reduzida. A área será preenchida se a contagem for diferente de zero quando a linha atinge fora da figura.  
  
 Quando um aplicativo terminar de usar uma região criada com o `CreatePolygonRgn` função, ele deve selecionar a região fora do contexto de dispositivo e use o `DeleteObject` função removê-lo.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView #146](../../mfc/codesnippet/cpp/crgn-class_3.cpp)]  
  
##  <a name="createpolypolygonrgn"></a>CRgn::CreatePolyPolygonRgn  
 Cria uma região consiste em uma série de polígonos fechados.  
  
```  
BOOL CreatePolyPolygonRgn(
    LPPOINT lpPoints,  
    LPINT lpPolyCounts,  
    int nCount,  
    int nPolyFillMode);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpPoints`  
 Aponta para uma matriz de **ponto** estruturas ou uma matriz de `CPoint` objetos que define os vértices de polígonos. Cada polígono deve ser explicitamente fechado porque o sistema não fechá-los automaticamente. Os polígonos são especificados consecutivamente. O **ponto** estrutura tem a seguinte forma:  
  
 `typedef struct tagPOINT {`  
  
 `int x;`  
  
 `int y;`  
  
 `} POINT;`  
  
 `lpPolyCounts`  
 Aponta para uma matriz de inteiros. O primeiro inteiro Especifica o número de vértices no primeiro polígono no `lpPoints` matriz, o segundo inteiro Especifica o número de vértices no polígono segundo e assim por diante.  
  
 `nCount`  
 Especifica o número total de inteiros no `lpPolyCounts` matriz.  
  
 `nPolyFillMode`  
 Especifica o modo de preenchimento de polígono. Esse valor pode ser **alternativo** ou **CONTORNO**.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a operação foi bem-sucedida. Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 A região resultante é armazenada no `CRgn` objeto.  
  
 Os polígonos podem estar separados, ou eles podem se sobrepor.  
  
 O tamanho de uma região é limitado a 64 KB de memória ou de unidades lógicas de 32.767 a 32.767, o que for menor.  
  
 Quando o modo de preenchimento de polígono é **alternativo**, o sistema preenche a área entre os lados do polígono ímpares e pares em cada linha de verificação. Ou seja, o sistema preenche a área entre o primeiro e o segundo lado, entre o terceiro e quarto lado e assim por diante.  
  
 Quando o modo de preenchimento de polígono é **CONTORNO**, o sistema usa a direção na qual uma figura foi desenhada para determinar se uma área de preenchimento. Cada segmento de linha em um polígono é desenhado no sentido horário ou sentido anti-horário. Sempre que uma linha imaginária extraída de uma área fechada para fora de uma figura passa por um segmento de linha no sentido horário, uma contagem é incrementada. Quando a linha passa por um segmento de linha no sentido anti-horário, a contagem é reduzida. A área será preenchida se a contagem for diferente de zero quando a linha atinge fora da figura.  
  
 Quando um aplicativo terminar de usar uma região criada com o `CreatePolyPolygonRgn` função, ele deve selecionar a região fora do contexto de dispositivo e use o [CGDIObject::DeleteObject](../../mfc/reference/cgdiobject-class.md#deleteobject) a função de membro para removê-lo.  
  
##  <a name="createrectrgn"></a>CRgn::CreateRectRgn  
 Cria uma região retangular que é armazenada no `CRgn` objeto.  
  
```  
BOOL CreateRectRgn(
    int x1,  
    int y1,  
    int x2,  
    int y2);
```  
  
### <a name="parameters"></a>Parâmetros  
 `x1`  
 Especifica a coordenada x lógica do canto superior esquerdo da região.  
  
 `y1`  
 Especifica a coordenada y lógica do canto superior esquerdo da região.  
  
 `x2`  
 Especifica a coordenada x lógica do canto inferior direito da região.  
  
 `y2`  
 Especifica a coordenada y lógica do canto inferior direito da região.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a operação foi bem-sucedida. Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O tamanho de uma região é limitado a 64 KB de memória ou de unidades lógicas de 32.767 a 32.767, o que for menor.  
  
 Quando terminou de usar uma região criada por `CreateRectRgn`, um aplicativo deve usar o [CGDIObject::DeleteObject](../../mfc/reference/cgdiobject-class.md#deleteobject) a função de membro para remover a região.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView #147](../../mfc/codesnippet/cpp/crgn-class_4.cpp)]  
  
 Para obter um exemplo adicional, consulte [CRgn::CombineRgn](#combinergn).  
  
##  <a name="createrectrgnindirect"></a>CRgn::CreateRectRgnIndirect  
 Cria uma região retangular que é armazenada no `CRgn` objeto.  
  
```  
BOOL CreateRectRgnIndirect(LPCRECT lpRect);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpRect`  
 Aponta para um `RECT` estrutura ou `CRect` objeto que contém as coordenadas lógicas dos cantos superior esquerdo e direito inferior da região. O `RECT` estrutura tem a seguinte forma:  
  
 `typedef struct tagRECT {`  
  
 `int left;`  
  
 `int top;`  
  
 `int right;`  
  
 `int bottom;`  
  
 `} RECT;`  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a operação foi bem-sucedida. Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O tamanho de uma região é limitado a 64 KB de memória ou de unidades lógicas de 32.767 a 32.767, o que for menor.  
  
 Quando terminou de usar uma região criada por `CreateRectRgnIndirect`, um aplicativo deve usar o [CGDIObject::DeleteObject](../../mfc/reference/cgdiobject-class.md#deleteobject) a função de membro para remover a região.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView #148](../../mfc/codesnippet/cpp/crgn-class_5.cpp)]  
  
##  <a name="createroundrectrgn"></a>CRgn::CreateRoundRectRgn  
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
 `x1`  
 Especifica a coordenada x lógica do canto superior esquerdo da região.  
  
 `y1`  
 Especifica a coordenada y lógica do canto superior esquerdo da região.  
  
 `x2`  
 Especifica a coordenada x lógica do canto inferior direito da região.  
  
 `y2`  
 Especifica a coordenada y lógica do canto inferior direito da região.  
  
 *X3*  
 Especifica a largura da elipse usada para criar os cantos arredondados.  
  
 `y3`  
 Especifica a altura da elipse usada para criar os cantos arredondados.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a operação foi bem-sucedida. Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O tamanho de uma região é limitado a 64 KB de memória ou de unidades lógicas de 32.767 a 32.767, o que for menor.  
  
 Quando um aplicativo terminar de usar uma região criada com o `CreateRoundRectRgn` função, ele deve selecionar a região fora do contexto de dispositivo e use o [CGDIObject::DeleteObject](../../mfc/reference/cgdiobject-class.md#deleteobject) a função de membro para removê-lo.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView #149](../../mfc/codesnippet/cpp/crgn-class_6.cpp)]  
  
##  <a name="crgn"></a>CRgn::CRgn  
 Constrói um objeto `CRgn`.  
  
```  
CRgn();
```  
  
### <a name="remarks"></a>Comentários  
 O `m_hObject` membro de dados não contém uma região do Windows GDI válida até que o objeto é inicializado com um ou mais dos outros `CRgn` funções de membro.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para [CRgn::CreateRoundRectRgn](#createroundrectrgn).  
  
##  <a name="equalrgn"></a>CRgn::EqualRgn  
 Determina se a região é equivalente à região de armazenados no `CRgn` objeto.  
  
```  
BOOL EqualRgn(CRgn* pRgn) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `pRgn`  
 Identifica uma região.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se as duas regiões são equivalentes; Caso contrário, 0.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView #150](../../mfc/codesnippet/cpp/crgn-class_7.cpp)]  
  
##  <a name="fromhandle"></a>CRgn::FromHandle  
 Retorna um ponteiro para um `CRgn` objeto quando é fornecido um identificador para uma região do Windows.  
  
```  
static CRgn* PASCAL FromHandle(HRGN hRgn);
```  
  
### <a name="parameters"></a>Parâmetros  
 `hRgn`  
 Especifica um identificador para uma região do Windows.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para um `CRgn` objeto. Se a função não foi bem-sucedida, o valor de retorno é **nulo**.  
  
### <a name="remarks"></a>Comentários  
 Se um `CRgn` objeto já não está anexado para o identificador de um temporário `CRgn` objeto é criado e anexado. Este temporário `CRgn` objeto é válido somente até a próxima vez que o aplicativo tem tempo ocioso em seu loop de evento, em que ponto o gráfico temporário todos os objetos serão excluídos. Outra maneira de dizer isso é que o objeto temporário é válido apenas durante o processamento da mensagem de uma janela.  
  
##  <a name="getregiondata"></a>CRgn::GetRegionData  
 Preenche o buffer especificado com dados que descrevem a região.  
  
```  
int GetRegionData(
    LPRGNDATA lpRgnData,  
    int nCount) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpRgnData`  
 Aponta para um [RGNDATA](../../mfc/reference/rgndata-structure.md) estrutura de dados que recebe as informações. Se esse parâmetro for **nulo**, o valor de retorno contém o número de bytes necessários para os dados da região.  
  
 `nCount`  
 Especifica o tamanho, em bytes, do `lpRgnData` buffer.  
  
### <a name="return-value"></a>Valor de retorno  
 Se a função tiver êxito e `nCount` Especifica um número adequado de bytes, o valor retornado é sempre `nCount`. Se a função falhar, ou se `nCount` Especifica menor que o número adequado de bytes, o valor de retorno é 0 (erro).  
  
### <a name="remarks"></a>Comentários  
 Esses dados incluem as dimensões dos retângulos que compõem a região. Essa função é usada em conjunto com o `CRgn::CreateFromData` função.  
  
##  <a name="getrgnbox"></a>CRgn::GetRgnBox  
 Recupera as coordenadas do retângulo delimitador do `CRgn` objeto.  
  
```  
int GetRgnBox(LPRECT lpRect) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpRect`  
 Aponta para um `RECT` estrutura ou `CRect` objeto para receber as coordenadas do retângulo delimitador. O `RECT` estrutura tem a seguinte forma:  
  
 `typedef struct tagRECT {`  
  
 `int left;`  
  
 `int top;`  
  
 `int right;`  
  
 `int bottom;`  
  
 `} RECT;`  
  
### <a name="return-value"></a>Valor de retorno  
 Especifica o tipo da região. Ele pode ser qualquer um dos seguintes valores:  
  
- **COMPLEXREGION** região tem bordas de sobreposição.  
  
- **NULLREGION** região está vazia.  
  
- **Erro** `CRgn` objeto não especifica uma região válida.  
  
- **SIMPLEREGION** região tem sem bordas sobrepostas.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para [CRgn::CreatePolygonRgn](#createpolygonrgn).  
  
##  <a name="offsetrgn"></a>CRgn::OffsetRgn  
 Move a região armazenada no `CRgn` objeto pelos deslocamentos especificados.  
  
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
  
 `point`  
 A coordenada x do `point` Especifica o número de unidades para mover para a esquerda ou direita. A coordenada y do `point` Especifica o número de unidades para mover para cima ou para baixo. O `point` parâmetro pode ser um **ponto** estrutura ou um `CPoint` objeto.  
  
### <a name="return-value"></a>Valor de retorno  
 Tipo da nova região. Ele pode ser qualquer um dos seguintes valores:  
  
- **COMPLEXREGION** região tem bordas de sobreposição.  
  
- **Erro** o identificador de região não é válido.  
  
- **NULLREGION** região está vazia.  
  
- **SIMPLEREGION** região tem sem bordas sobrepostas.  
  
### <a name="remarks"></a>Comentários  
 A função move a região *x* unidades no eixo e *y* unidades no eixo y.  
  
 Os valores de coordenada de uma região devem ser menor ou igual a 32.767 e maior ou igual a -32.768. O *x* e *y* parâmetros devem ser escolhidos com cuidado para evitar que as coordenadas de região inválido.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para [CRgn::CreateEllipticRgn](#createellipticrgn).  
  
##  <a name="operator_hrgn"></a>CRgn::operator HRGN  
 Use este operador para obter o identificador de Windows GDI anexado do `CRgn` objeto.  
  
```  
operator HRGN() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Se for bem-sucedido, um identificador para o objeto Windows GDI representado pelo `CRgn` objeto; caso contrário, **nulo**.  
  
### <a name="remarks"></a>Comentários  
 Esse operador é um operador de conversão, que dá suporte ao uso direto de um **HRGN** objeto.  
  
 Para obter mais informações sobre como usar objetos gráficos, consulte o artigo [objetos de gráfico](http://msdn.microsoft.com/library/windows/desktop/dd144962) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="ptinregion"></a>CRgn::PtInRegion  
 Verifica se o ponto fornecido por *x* e *y* na região armazenado no `CRgn` objeto.  
  
```  
BOOL PtInRegion(
    int x,  
    int y) const;  
  
BOOL PtInRegion(POINT point) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 *x*  
 Especifica a coordenada x lógica do ponto de teste.  
  
 *y*  
 Especifica a coordenada y lógica do ponto de teste.  
  
 `point`  
 As coordenadas x e y do `point` especificar as coordenadas x e y do ponto para testar o valor de. O `point` parâmetro pode ser um **ponto** estrutura ou um `CPoint` objeto.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o ponto estiver na região. Caso contrário, 0.  
  
##  <a name="rectinregion"></a>CRgn::RectInRegion  
 Determina se qualquer parte do retângulo especificado por `lpRect` está dentro dos limites da região armazenados no `CRgn` objeto.  
  
```  
BOOL RectInRegion(LPCRECT lpRect) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpRect`  
 Aponta para um `RECT` estrutura ou `CRect` objeto. O `RECT` estrutura tem a seguinte forma:  
  
 `typedef struct tagRECT {`  
  
 `int left;`  
  
 `int top;`  
  
 `int right;`  
  
 `int bottom;`  
  
 `} RECT;`  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se qualquer parte do retângulo especificado está dentro dos limites de região; Caso contrário, 0.  
  
##  <a name="setrectrgn"></a>CRgn::SetRectRgn  
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
 `x1`  
 Especifica a coordenada x do canto superior esquerdo da região retangular.  
  
 `y1`  
 Especifica a coordenada y do canto superior esquerdo da região retangular.  
  
 `x2`  
 Especifica a coordenada x do canto inferior direito da área retangular.  
  
 `y2`  
 Especifica a coordenada y do canto inferior direito da área retangular.  
  
 `lpRect`  
 Especifica a região retangular. Pode ser um ponteiro para um `RECT` estrutura ou um `CRect` objeto.  
  
### <a name="remarks"></a>Comentários  
 Ao contrário de [CreateRectRgn](#createrectrgn), no entanto, ele não alocará nenhuma memória adicional do heap de aplicativo local do Windows. Em vez disso, ele usa o espaço alocado para a região é armazenada no `CRgn` objeto. Isso significa que o `CRgn` objeto já deve ter sido inicializado com uma região do Windows válida antes de chamar `SetRectRgn`. Os pontos de fornecido pelo `x1`, `y1`, `x2`, e `y2` Especifica o tamanho mínimo de espaço alocado.  
  
 Use esta função em vez do `CreateRectRgn` a função de membro para evitar chamadas para o Gerenciador de memória local.  
  
## <a name="see-also"></a>Consulte também  
 [Classe CWnd](../../mfc/reference/cwnd-class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)




