---
title: "Classe CRgn | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "CRgn"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "HRGN"
  - "Classe CRgn"
  - "regiões, MFC"
ms.assetid: d904da84-76aa-481e-8780-b09485f49e64
caps.latest.revision: 23
caps.handback.revision: 23
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe CRgn
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Encapsula uma região do Windows gráficos dispositivo GDI (interface).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CRgn : public CGdiObject  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CRgn::CRgn](#crgn__crgn)|Constrói um objeto `CRgn`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CRgn::CombineRgn](#crgn__combinergn)|Define um `CRgn` para que seja equivalente a união de dois especificado do objeto `CRgn` objetos.|  
|[CRgn::CopyRgn](#crgn__copyrgn)|Define um `CRgn` para que ele seja uma cópia de um especificado do objeto `CRgn` objeto.|  
|[CRgn::CreateEllipticRgn](#crgn__createellipticrgn)|Inicializa uma `CRgn` objeto com uma região elíptico.|  
|[CRgn::CreateEllipticRgnIndirect](#crgn__createellipticrgnindirect)|Inicializa uma `CRgn` objeto com uma região elíptico definida por um [RECT](RECT%20Structure1.md) estrutura.|  
|[CRgn::CreateFromData](#crgn__createfromdata)|Cria uma região de dados de região e transformação determinados.|  
|[CRgn::CreateFromPath](#crgn__createfrompath)|Cria uma região do caminho que está selecionado no contexto de determinado dispositivo.|  
|[CRgn::CreatePolygonRgn](#crgn__createpolygonrgn)|Inicializa uma `CRgn` objeto com uma região poligonal. O sistema fecha o polígono automaticamente, se necessário, desenhando uma linha do último vértice ao primeiro.|  
|[CRgn::CreatePolyPolygonRgn](#crgn__createpolypolygonrgn)|Inicializa uma `CRgn` objeto com uma região consiste em uma série de polígonos fechados. Os polígonos podem ser separados, ou eles podem se sobrepor.|  
|[CRgn::CreateRectRgn](#crgn__createrectrgn)|Inicializa uma `CRgn` objeto com uma região retangular.|  
|[CRgn::CreateRectRgnIndirect](#crgn__createrectrgnindirect)|Inicializa uma `CRgn` objeto com uma região retangular definida por um [RECT](RECT%20Structure1.md) estrutura.|  
|[CRgn::CreateRoundRectRgn](#crgn__createroundrectrgn)|Inicializa uma `CRgn` objeto com uma região retangular com cantos arredondados.|  
|[CRgn::EqualRgn](#crgn__equalrgn)|Verifica se dois `CRgn` objetos para determinar se eles são equivalentes.|  
|[CRgn::FromHandle](#crgn__fromhandle)|Retorna um ponteiro para um `CRgn` objeto quando recebe um identificador para uma região do Windows.|  
|[CRgn::GetRegionData](#crgn__getregiondata)|Preenche o buffer especificado com dados que descrevem a determinada região.|  
|[CRgn::GetRgnBox](#crgn__getrgnbox)|Recupera as coordenadas do retângulo delimitador de uma `CRgn` objeto.|  
|[CRgn::OffsetRgn](#crgn__offsetrgn)|Move um `CRgn` objeto pelos deslocamentos especificados.|  
|[CRgn::PtInRegion](#crgn__ptinregion)|Determina se um ponto especificado está na região.|  
|[CRgn::RectInRegion](#crgn__rectinregion)|Determina se qualquer parte de um retângulo especificado está dentro dos limites da região.|  
|[CRgn::SetRectRgn](#crgn__setrectrgn)|Conjuntos de `CRgn` objeto para a região retangular especificada.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CRgn::operator HRGN](#crgn__operator_hrgn)|Retorna o identificador do Windows contido a `CRgn` objeto.|  
  
## <a name="remarks"></a>Comentários  
 Uma região é uma área elíptica ou poligonal dentro de uma janela. Para usar regiões, é usa as funções de membro da classe `CRgn` com as funções de recorte definidas como membros da classe `CDC`.  
  
 As funções de membro de `CRgn` criar, alterar e recuperar informações sobre o objeto de região para a qual eles são chamados.  
  
 Para obter mais informações sobre como usar `CRgn`, consulte [objetos gráficos](../../mfc/graphic-objects.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CGdiObject](../../mfc/reference/cgdiobject-class.md)  
  
 `CRgn`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxwin. h  
  
##  <a name="a-namecrgncombinergna-crgncombinergn"></a><a name="crgn__combinergn"></a>  CRgn::CombineRgn  
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
  
- **RGN_AND** usa áreas sobrepostas de ambas as regiões (interseção).  
  
- **RGN_COPY** cria uma cópia da região 1 (identificado por `pRgn1`).  
  
- **RGN_DIFF** cria uma região consiste em áreas de região 1 (identificado por `pRgn1`) que não fazem parte da região 2 (identificado por `pRgn2`).  
  
- **RGN_OR** combina duas regiões em sua totalidade (união).  
  
- **RGN_XOR** combina duas regiões, mas remove áreas sobrepostas.  
  
### <a name="return-value"></a>Valor de retorno  
 Especifica o tipo da região de dados resultante. Ele pode ser um dos seguintes valores:  
  
- **COMPLEXREGION** nova região tem bordas de sobreposição.  
  
- **ERRO** nenhuma nova região criada.  
  
- **NULLREGION** nova região está vazia.  
  
- **SIMPLEREGION** nova região tem sem bordas sobrepostas.  
  
### <a name="remarks"></a>Comentários  
 As regiões são combinadas como especificado pelo `nCombineMode`.  
  
 Os dois especificados regiões são combinadas e o identificador de região resultante é armazenado no `CRgn` objeto. Portanto, qualquer região é armazenado no `CRgn` objeto é substituído pela região combinado.  
  
 O tamanho de uma região é limitado a 64 KB de memória ou de unidades lógicas de 32.767 a 32.767, o que for menor.  
  
 Use [CopyRgn](#crgn__copyrgn) simplesmente copiar uma região em outra região.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView#144](../../mfc/codesnippet/CPP/crgn-class_1.cpp)]  
  
##  <a name="a-namecrgncopyrgna-crgncopyrgn"></a><a name="crgn__copyrgn"></a>  CRgn::CopyRgn  
 Copia a região definida pelo `pRgnSrc` para o `CRgn` objeto.  
  
```  
int CopyRgn(CRgn* pRgnSrc);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pRgnSrc`  
 Identifica uma região existente.  
  
### <a name="return-value"></a>Valor de retorno  
 Especifica o tipo da região de dados resultante. Ele pode ser um dos seguintes valores:  
  
- **COMPLEXREGION** nova região tem bordas de sobreposição.  
  
- **ERRO** nenhuma nova região criada.  
  
- **NULLREGION** nova região está vazia.  
  
- **SIMPLEREGION** nova região tem sem bordas sobrepostas.  
  
### <a name="remarks"></a>Comentários  
 A nova região substitui a região armazenada anteriormente no `CRgn` objeto. Essa função é um caso especial do [CombineRgn](#crgn__combinergn) função de membro.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CRgn::CreateEllipticRgn](#crgn__createellipticrgn).  
  
##  <a name="a-namecrgncreateellipticrgna-crgncreateellipticrgn"></a><a name="crgn__createellipticrgn"></a>  CRgn::CreateEllipticRgn  
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
 A região é definida, o retângulo delimitador especificado por `x1`, `y1`, `x2`, e `y2`. A região é armazenada no `CRgn` objeto.  
  
 O tamanho de uma região é limitado a 64 KB de memória ou de unidades lógicas de 32.767 a 32.767, o que for menor.  
  
 Quando tiver concluído usando uma região criada com o `CreateEllipticRgn` função, um aplicativo deve selecionar a região fora do contexto de dispositivo e use o `DeleteObject` função removê-lo.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView#145](../../mfc/codesnippet/CPP/crgn-class_2.cpp)]  
  
##  <a name="a-namecrgncreateellipticrgnindirecta-crgncreateellipticrgnindirect"></a><a name="crgn__createellipticrgnindirect"></a>  CRgn::CreateEllipticRgnIndirect  
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
 A região é definida pela estrutura ou objeto apontado pelo `lpRect` e é armazenado no `CRgn` objeto.  
  
 O tamanho de uma região é limitado a 64 KB de memória ou de unidades lógicas de 32.767 a 32.767, o que for menor.  
  
 Quando tiver concluído usando uma região criada com o `CreateEllipticRgnIndirect` função, um aplicativo deve selecionar a região fora do contexto de dispositivo e use o `DeleteObject` função removê-lo.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CRgn::CreateRectRgnIndirect](#crgn__createrectrgnindirect).  
  
##  <a name="a-namecrgncreatefromdataa-crgncreatefromdata"></a><a name="crgn__createfromdata"></a>  CRgn::CreateFromData  
 Cria uma região de dados de região e transformação determinados.  
  
```  
BOOL CreateFromData(
    const XFORM* lpXForm,  
    int nCount,  
    const RGNDATA* pRgnData);
```  
  
### <a name="parameters"></a>Parâmetros  
 *lpXForm*  
 Aponta para um [XFORM](../../mfc/reference/xform-structure.md) estrutura de dados que define a transformação a ser realizada na região. Se esse ponteiro é **NULO**, a transformação de identidade é usada.  
  
 `nCount`  
 Especifica o número de bytes apontada por `pRgnData`.  
  
 `pRgnData`  
 Aponta para um [RGNDATA](../../mfc/reference/rgndata-structure.md) estrutura de dados que contém os dados da região.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a função for bem-sucedida; caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Um aplicativo pode recuperar dados para uma região chamando o `CRgn::GetRegionData` função.  
  
##  <a name="a-namecrgncreatefrompatha-crgncreatefrompath"></a><a name="crgn__createfrompath"></a>  CRgn::CreateFromPath  
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
 O contexto de dispositivo identificado pelo `pDC` parâmetro deve conter um caminho fechado. Depois de `CreateFromPath` converte um caminho em uma região, o Windows descarta o caminho fechado do contexto do dispositivo.  
  
##  <a name="a-namecrgncreatepolygonrgna-crgncreatepolygonrgn"></a><a name="crgn__createpolygonrgn"></a>  CRgn::CreatePolygonRgn  
 Cria uma região poligonal.  
  
```  
BOOL CreatePolygonRgn(
    LPPOINT lpPoints,  
    int nCount,  
    int nMode);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpPoints`  
 Aponta para uma matriz de **PONTO** estruturas ou uma matriz de `CPoint` objetos. Cada estrutura Especifica as coordenadas x e y de um vértice do polígono. O **PONTO** estrutura tem a seguinte forma:  
  
 `typedef struct tagPOINT {`  
  
 `int x;`  
  
 `int y;`  
  
 `} POINT;`  
  
 `nCount`  
 Especifica o número de **PONTO** estruturas ou `CPoint` objetos na matriz apontada por `lpPoints`.  
  
 `nMode`  
 Especifica o modo de preenchimento para a região. Esse parâmetro pode ser **ALTERNATIVO** ou **ENROLAMENTO**.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a operação foi bem-sucedida. Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O sistema fecha o polígono automaticamente, se necessário, desenhando uma linha do último vértice ao primeiro. A região resultante é armazenada no `CRgn` objeto.  
  
 O tamanho de uma região é limitado a 64 KB de memória ou de unidades lógicas de 32.767 a 32.767, o que for menor.  
  
 Quando o modo de preenchimento de polígono é **ALTERNATIVO**, o sistema preenche a área entre os lados do polígono ímpares e pares em cada linha de verificação. Ou seja, o sistema preenche a área entre o primeiro e o segundo lado, entre o terceiro e quarto lado e assim por diante.  
  
 Quando o modo de preenchimento de polígono é **ENROLAMENTO**, o sistema usa a direção na qual uma figura foi desenhada para determinar se deve preencher uma área. Cada segmento de linha em um polígono é desenhado em um sentido horário ou sentido anti-horário. Sempre que uma linha imaginária desenhada a partir de uma área fechada para fora de uma figura que passa por um segmento de linha no sentido horário, uma contagem é incrementada. Quando a linha passa por um segmento de linha no sentido anti-horário, a contagem é diminuída. A área é preenchida se a contagem for diferente de zero quando a linha alcança a parte externa da figura.  
  
 Quando um aplicativo tiver terminado de usar uma região criada com o `CreatePolygonRgn` função, ela deve selecionar a região fora do contexto de dispositivo e use o `DeleteObject` função removê-lo.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView#146](../../mfc/codesnippet/CPP/crgn-class_3.cpp)]  
  
##  <a name="a-namecrgncreatepolypolygonrgna-crgncreatepolypolygonrgn"></a><a name="crgn__createpolypolygonrgn"></a>  CRgn::CreatePolyPolygonRgn  
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
 Aponta para uma matriz de **PONTO** estruturas ou uma matriz de `CPoint` objetos que define os vértices dos polígonos. Cada polígono deve ser explicitamente fechado porque o sistema não fechá-los automaticamente. Os polígonos são especificados consecutivas. O **PONTO** estrutura tem a seguinte forma:  
  
 `typedef struct tagPOINT {`  
  
 `int x;`  
  
 `int y;`  
  
 `} POINT;`  
  
 `lpPolyCounts`  
 Aponta para uma matriz de inteiros. O primeiro inteiro Especifica o número de vértices do polígono primeiro na `lpPoints` matriz, o segundo inteiro Especifica o número de vértices na segunda polígono e assim por diante.  
  
 `nCount`  
 Especifica o número total de números inteiros na `lpPolyCounts` matriz.  
  
 `nPolyFillMode`  
 Especifica o modo de preenchimento de polígono. Esse valor pode ser **ALTERNATIVO** ou **ENROLAMENTO**.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a operação foi bem-sucedida. Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 A região resultante é armazenada no `CRgn` objeto.  
  
 Os polígonos podem ser separados, ou eles podem se sobrepor.  
  
 O tamanho de uma região é limitado a 64 KB de memória ou de unidades lógicas de 32.767 a 32.767, o que for menor.  
  
 Quando o modo de preenchimento de polígono é **ALTERNATIVO**, o sistema preenche a área entre os lados do polígono ímpares e pares em cada linha de verificação. Ou seja, o sistema preenche a área entre o primeiro e o segundo lado, entre o terceiro e quarto lado e assim por diante.  
  
 Quando o modo de preenchimento de polígono é **ENROLAMENTO**, o sistema usa a direção na qual uma figura foi desenhada para determinar se deve preencher uma área. Cada segmento de linha em um polígono é desenhado em um sentido horário ou sentido anti-horário. Sempre que uma linha imaginária desenhada a partir de uma área fechada para fora de uma figura que passa por um segmento de linha no sentido horário, uma contagem é incrementada. Quando a linha passa por um segmento de linha no sentido anti-horário, a contagem é diminuída. A área é preenchida se a contagem for diferente de zero quando a linha alcança a parte externa da figura.  
  
 Quando um aplicativo tiver terminado de usar uma região criada com o `CreatePolyPolygonRgn` função, ela deve selecionar a região fora do contexto de dispositivo e use o [CGDIObject::DeleteObject](../../mfc/reference/cgdiobject-class.md#cgdiobject__deleteobject) a função de membro para removê-lo.  
  
##  <a name="a-namecrgncreaterectrgna-crgncreaterectrgn"></a><a name="crgn__createrectrgn"></a>  CRgn::CreateRectRgn  
 Cria uma região retangular que é armazenada na `CRgn` objeto.  
  
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
  
 Quando tiver concluído usando uma região criada por `CreateRectRgn`, um aplicativo deve usar o [CGDIObject::DeleteObject](../../mfc/reference/cgdiobject-class.md#cgdiobject__deleteobject) a função de membro para remover a região.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView#147](../../mfc/codesnippet/CPP/crgn-class_4.cpp)]  
  
 Para obter um exemplo adicional, consulte [CRgn::CombineRgn](#crgn__combinergn).  
  
##  <a name="a-namecrgncreaterectrgnindirecta-crgncreaterectrgnindirect"></a><a name="crgn__createrectrgnindirect"></a>  CRgn::CreateRectRgnIndirect  
 Cria uma região retangular que é armazenada na `CRgn` objeto.  
  
```  
BOOL CreateRectRgnIndirect(LPCRECT lpRect);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpRect`  
 Aponta para um `RECT` estrutura ou `CRect` objeto que contém as coordenadas lógicas dos cantos superior esquerda e inferior direita da região. O `RECT` estrutura tem a seguinte forma:  
  
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
  
 Quando tiver concluído usando uma região criada por `CreateRectRgnIndirect`, um aplicativo deve usar o [CGDIObject::DeleteObject](../../mfc/reference/cgdiobject-class.md#cgdiobject__deleteobject) a função de membro para remover a região.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView#148](../../mfc/codesnippet/CPP/crgn-class_5.cpp)]  
  
##  <a name="a-namecrgncreateroundrectrgna-crgncreateroundrectrgn"></a><a name="crgn__createroundrectrgn"></a>  CRgn::CreateRoundRectRgn  
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
  
 Quando um aplicativo tiver terminado de usar uma região criada com o `CreateRoundRectRgn` função, ela deve selecionar a região fora do contexto de dispositivo e use o [CGDIObject::DeleteObject](../../mfc/reference/cgdiobject-class.md#cgdiobject__deleteobject) a função de membro para removê-lo.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView#149](../../mfc/codesnippet/CPP/crgn-class_6.cpp)]  
  
##  <a name="a-namecrgncrgna-crgncrgn"></a><a name="crgn__crgn"></a>  CRgn::CRgn  
 Constrói um objeto `CRgn`.  
  
```  
CRgn();
```  
  
### <a name="remarks"></a>Comentários  
 O `m_hObject` membro de dados não contém uma região GDI do Windows válida até que o objeto é inicializado com um ou mais dos outros `CRgn` funções de membro.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CRgn::CreateRoundRectRgn](#crgn__createroundrectrgn).  
  
##  <a name="a-namecrgnequalrgna-crgnequalrgn"></a><a name="crgn__equalrgn"></a>  CRgn::EqualRgn  
 Determina se a determinada região é equivalente à região armazenado no `CRgn` objeto.  
  
```  
BOOL EqualRgn(CRgn* pRgn) const;

 
```  
  
### <a name="parameters"></a>Parâmetros  
 `pRgn`  
 Identifica uma região.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se duas regiões forem equivalentes; Caso contrário, 0.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView#150](../../mfc/codesnippet/CPP/crgn-class_7.cpp)]  
  
##  <a name="a-namecrgnfromhandlea-crgnfromhandle"></a><a name="crgn__fromhandle"></a>  CRgn::FromHandle  
 Retorna um ponteiro para um `CRgn` objeto quando recebe um identificador para uma região do Windows.  
  
```  
static CRgn* PASCAL FromHandle(HRGN hRgn);
```  
  
### <a name="parameters"></a>Parâmetros  
 `hRgn`  
 Especifica um identificador para uma região do Windows.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para um `CRgn` objeto. Se a função não for bem-sucedida, o valor de retorno é **NULO**.  
  
### <a name="remarks"></a>Comentários  
 Se um `CRgn` objeto já não está anexado ao identificador, um temporário `CRgn` objeto é criado e anexado. Esse temporário `CRgn` objeto é válido somente até a próxima vez que o aplicativo tiver tempo ocioso em seu loop de evento, em que ponto gráfico temporário todos os objetos são excluídos. Outra maneira de dizer isso é que o objeto temporário só é válido durante o processamento da mensagem de uma janela.  
  
##  <a name="a-namecrgngetregiondataa-crgngetregiondata"></a><a name="crgn__getregiondata"></a>  CRgn::GetRegionData  
 Preenche o buffer especificado com dados que descrevem a região.  
  
```  
int GetRegionData(
    LPRGNDATA lpRgnData,  
    int nCount) const;

 
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpRgnData`  
 Aponta para um [RGNDATA](../../mfc/reference/rgndata-structure.md) estrutura de dados que recebe as informações. Se esse parâmetro for **NULO**, o valor de retorno contém o número de bytes necessários para os dados da região.  
  
 `nCount`  
 Especifica o tamanho, em bytes, do `lpRgnData` buffer.  
  
### <a name="return-value"></a>Valor de retorno  
 Se a função for bem-sucedida e `nCount` Especifica um número adequado de bytes, o valor de retorno é sempre `nCount`. Se a função falhar, ou se `nCount` Especifica menor que o número adequado de bytes, o valor de retorno é 0 (erro).  
  
### <a name="remarks"></a>Comentários  
 Esses dados incluem as dimensões dos retângulos que formam a região. Essa função é usada em conjunto com o `CRgn::CreateFromData` função.  
  
##  <a name="a-namecrgngetrgnboxa-crgngetrgnbox"></a><a name="crgn__getrgnbox"></a>  CRgn::GetRgnBox  
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
  
- **COMPLEXREGION** região tiver bordas de sobreposição.  
  
- **NULLREGION** região está vazia.  
  
- **ERRO** `CRgn` objeto não especificar uma região válida.  
  
- **SIMPLEREGION** região tem sem bordas sobrepostas.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CRgn::CreatePolygonRgn](#crgn__createpolygonrgn).  
  
##  <a name="a-namecrgnoffsetrgna-crgnoffsetrgn"></a><a name="crgn__offsetrgn"></a>  CRgn::OffsetRgn  
 Move a região armazenada no `CRgn` objeto pelos deslocamentos especificados.  
  
```  
int OffsetRgn(
    int x,  
    int y);

 
int OffsetRgn(
    POINT point);
```  
  
### <a name="parameters"></a>Parâmetros  
 *x*  
 Especifica o número de unidades para mover para a esquerda ou direita.  
  
 *y*  
 Especifica o número de unidades para mover para cima ou para baixo.  
  
 `point`  
 A coordenada x do `point` Especifica o número de unidades para mover para a esquerda ou direita. A coordenada y do `point` Especifica o número de unidades para mover para cima ou para baixo. O `point` parâmetro pode ser um **PONTO** estrutura ou um `CPoint` objeto.  
  
### <a name="return-value"></a>Valor de retorno  
 Tipo da nova região. Ele pode ser qualquer um dos seguintes valores:  
  
- **COMPLEXREGION** região tiver bordas de sobreposição.  
  
- **ERRO** o identificador de região não é válido.  
  
- **NULLREGION** região está vazia.  
  
- **SIMPLEREGION** região tem sem bordas sobrepostas.  
  
### <a name="remarks"></a>Comentários  
 A função move a região *x* unidades no eixo e *y* unidades no eixo y.  
  
 Os valores de coordenada de uma região devem ser menor ou igual a 32.767 e maior ou igual a – 32.768. O *x* e *y* parâmetros devem ser escolhidos cuidadosamente para evitar que as coordenadas de região inválido.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CRgn::CreateEllipticRgn](#crgn__createellipticrgn).  
  
##  <a name="a-namecrgnoperatorhrgna-crgnoperator-hrgn"></a><a name="crgn__operator_hrgn"></a>  CRgn::operator HRGN  
 Usar esse operador para obter o identificador do Windows GDI anexado do `CRgn` objeto.  
  
' ' operador HRGN() const;

 
```  
  
### Return Value  
 If successful, a handle to the Windows GDI object represented by the `CRgn` object; otherwise **NULL**.  
  
### Remarks  
 This operator is a casting operator, which supports direct use of an **HRGN** object.  
  
 For more information about using graphic objects, see the article [Graphic Objects](http://msdn.microsoft.com/library/windows/desktop/dd144962) in the [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="crgn__ptinregion"></a>  CRgn::PtInRegion  
 Checks whether the point given by *x* and *y* is in the region stored in the `CRgn` object.  
  
```  
BOOL PtInRegion (int x,  
    int y) const;

 
 
PtInRegion BOOL (ponto) const;

 
```  
  
### Parameters  
 *x*  
 Specifies the logical x-coordinate of the point to test.  
  
 *y*  
 Specifies the logical y-coordinate of the point to test.  
  
 `point`  
 The x- and y-coordinates of `point` specify the x- and y-coordinates of the point to test the value of. The `point` parameter can either be a **POINT** structure or a `CPoint` object.  
  
### Return Value  
 Nonzero if the point is in the region; otherwise 0.  
  
##  <a name="crgn__rectinregion"></a>  CRgn::RectInRegion  
 Determines whether any part of the rectangle specified by `lpRect` is within the boundaries of the region stored in the `CRgn` object.  
  
```  
BOOL RectInRegion(LPCRECT lpRect) const;

 
```  
  
### Parameters  
 `lpRect`  
 Points to a `RECT` structure or `CRect` object. The `RECT` structure has the following form:  
  
 `typedef struct tagRECT {`  
  
 `int left;`  
  
 `int top;`  
  
 `int right;`  
  
 `int bottom;`  
  
 `} RECT;`  
  
### Return Value  
 Nonzero if any part of the specified rectangle lies within the boundaries of the region; otherwise 0.  
  
##  <a name="crgn__setrectrgn"></a>  CRgn::SetRectRgn  
 Creates a rectangular region.  
  
```  
void SetRectRgn (int x1,  
    int y1,  
    int x2,  
    int y2);

 
void SetRectRgn (LPCRECT lpRect);
```  
  
### Parameters  
 `x1`  
 Specifies the x-coordinate of the upper-left corner of the rectangular region.  
  
 `y1`  
 Specifies the y-coordinate of the upper-left corner of the rectangular region.  
  
 `x2`  
 Specifies the x-coordinate of the lower-right corner of the rectangular region.  
  
 `y2`  
 Specifies the y-coordinate of the lower-right corner of the rectangular region.  
  
 `lpRect`  
 Specifies the rectangular region. Can be either a pointer to a `RECT` structure or a `CRect` object.  
  
### Remarks  
 Unlike [CreateRectRgn](#crgn__createrectrgn), however, it does not allocate any additional memory from the local Windows application heap. Instead, it uses the space allocated for the region stored in the `CRgn` object. This means that the `CRgn` object must already have been initialized with a valid Windows region before calling `SetRectRgn`. The points given by `x1`, `y1`, `x2`, and `y2` specify the minimum size of the allocated space.  
  
 Use this function instead of the `CreateRectRgn` member function to avoid calls to the local memory manager.  
  
## See Also  
 [CWnd Class](../Topic/CWnd%20Class.md)   
 [Hierarchy Chart](../../mfc/hierarchy-chart.md)



