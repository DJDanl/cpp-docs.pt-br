---
title: Classe CFont | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CFont
dev_langs:
- C++
helpviewer_keywords:
- CFont class
- GDI, font classes
- fonts, MFC classes
ms.assetid: 3fad6bfe-d6ce-4ab9-967a-5ce0aa102800
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
translationtype: Machine Translation
ms.sourcegitcommit: 0e0c08ddc57d437c51872b5186ae3fc983bb0199
ms.openlocfilehash: cc7ecfb850bf24013acdb55075eeb3d64d4994ee
ms.lasthandoff: 02/25/2017

---
# <a name="cfont-class"></a>Classe CFont
Encapsula uma fonte de GDI (interface) do dispositivo de gráficos Windows e fornece funções de membro para manipular a fonte.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CFont : public CGdiObject  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CFont::CFont](#cfont)|Constrói um objeto `CFont`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CFont::CreateFont](#createfont)|Inicializa uma `CFont` com as características especificadas.|  
|[CFont::CreateFontIndirect](#createfontindirect)|Inicializa uma `CFont` objeto com as características fornecido em um `LOGFONT` estrutura.|  
|[CFont::CreatePointFont](#createpointfont)|Inicializa um `CFont` com a altura especificada, medida em décimos de um ponto e a face de tipos.|  
|[CFont::CreatePointFontIndirect](#createpointfontindirect)|Mesmo que `CreateFontIndirect` exceto que a altura da fonte é medida em décimos de um ponto em vez de unidades lógicas.|  
|[CFont::FromHandle](#fromhandle)|Retorna um ponteiro para um `CFont` objeto quando é fornecido um Windows **HFONT**.|  
|[CFont::GetLogFont](#getlogfont)|Preenche um `LOGFONT` com informações sobre a fonte lógica anexada para o `CFont` objeto.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CFont::operator HFONT](#operator_hfont)|Retorna o identificador de fonte GDI do Windows conectado ao `CFont` objeto.|  
  
## <a name="remarks"></a>Comentários  
 Para usar um `CFont` de objeto, construir um `CFont` de objeto e anexar uma fonte do Windows com [CreateFont](#createfont), [CreateFontIndirect](#createfontindirect), [CreatePointFont](#createpointfont), ou [CreatePointFontIndirect](#createpointfontindirect)e, em seguida, usar funções de membro do objeto para manipular a fonte.  
  
 O `CreatePointFont` e `CreatePointFontIndirect` funções geralmente são mais fáceis de usar que `CreateFont` ou `CreateFontIndirect` desde que eles fazem a conversão para a altura da fonte de um tamanho de ponto de unidades lógicas automaticamente.  
  
 Para obter mais informações sobre `CFont`, consulte [objetos gráficos](../../mfc/graphic-objects.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CGdiObject](../../mfc/reference/cgdiobject-class.md)  
  
 `CFont`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxwin. h  
  
##  <a name="a-namecfonta--cfontcfont"></a><a name="cfont"></a>CFont::CFont  
 Constrói um objeto `CFont`.  
  
```  
CFont();
```  
  
### <a name="remarks"></a>Comentários  
 O objeto resultante deve ser inicializado com `CreateFont`, `CreateFontIndirect`, `CreatePointFont`, ou `CreatePointFontIndirect` antes de ser usada.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView&#70;](../../mfc/codesnippet/cpp/cfont-class_1.cpp)]  
  
##  <a name="a-namecreatefonta--cfontcreatefont"></a><a name="createfont"></a>CFont::CreateFont  
 Inicializa uma `CFont` objeto com as características especificadas.  
  
```  
BOOL CreateFont(
    int nHeight,  
    int nWidth,  
    int nEscapement,  
    int nOrientation,  
    int nWeight,  
    BYTE bItalic,  
    BYTE bUnderline,  
    BYTE cStrikeOut,  
    BYTE nCharSet,  
    BYTE nOutPrecision,  
    BYTE nClipPrecision,  
    BYTE nQuality,  
    BYTE nPitchAndFamily,  
    LPCTSTR lpszFacename);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nHeight`  
 Especifica a altura desejada (em unidades lógicas) da fonte. Consulte o `lfHeight` membro o [LOGFONT](http://msdn.microsoft.com/library/windows/desktop/dd145037)estrutura no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)] para obter uma descrição. O valor absoluto de `nHeight` não deve exceder 16.384 unidades de dispositivo após ele é convertido. Para todas as comparações de altura, o mapeador de fonte procura a maior fonte que não exceda o tamanho solicitado ou a fonte menor se todas as fontes excederem o tamanho solicitado.  
  
 `nWidth`  
 Especifica a largura média (em unidades lógicas) de caracteres na fonte. Se `nWidth` for 0, a taxa de proporção do dispositivo será comparada com a taxa de proporção de digitalização das fontes disponíveis para localizar a correspondência mais próxima, que é determinada pelo valor absoluto da diferença.  
  
 `nEscapement`  
 Especifica o ângulo (em unidades de 0,1 grau) entre o vetor de escape e o eixo x da superfície de exibição. O vetor de escape é a linha e as origens do primeiro e último caracteres em uma linha. O ângulo é medido no sentido anti-horário do eixo x. Consulte o `lfEscapement` membro o `LOGFONT` estrutura no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)] para obter mais informações.  
  
 `nOrientation`  
 Especifica o ângulo (em unidades de 0,1 grau) entre a linha de base de um caractere e o eixo x. O ângulo é medido no sentido anti-horário do eixo x para sistemas de coordenadas em que direção y é baixo e sentido anti-horário do eixo x para sistemas de coordenadas em que direção y está ativo.  
  
 `nWeight`  
 Especifica a espessura da fonte (em pixels coloridos por 1000). Consulte o `lfWeight` membro o `LOGFONT` estrutura no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)] para obter mais informações. Os valores descritos são aproximados; a aparência real depende da face de tipos. Algumas fontes têm apenas `FW_NORMAL`, `FW_REGULAR`, e `FW_BOLD` pesos. Se `FW_DONTCARE` for especificado, um peso padrão será usado.  
  
 `bItalic`  
 Especifica se a fonte está em itálico.  
  
 `bUnderline`  
 Especifica se a fonte está sublinhada.  
  
 `cStrikeOut`  
 Especifica se os caracteres na fonte são riscados. Especifica uma fonte riscado se definido como um valor diferente de zero.  
  
 `nCharSet`  
 Especifica setSee de caractere da fonte de `lfCharSet` membro no `LOGFONT` estrutura no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)] para obter uma lista de valores.  
  
 O conjunto de caracteres OEM depende do sistema.  
  
 Fontes com outros conjuntos de caracteres podem existir no sistema. Um aplicativo que usa uma fonte com um conjunto de caracteres desconhecido não deve tentar converter ou interpretar cadeias de caracteres a ser processado com essa fonte. Em vez disso, as cadeias de caracteres devem ser passadas diretamente para o driver de dispositivo de saída.  
  
 O mapeador de fonte não usa o `DEFAULT_CHARSET` valor. Um aplicativo pode usar esse valor para permitir que o nome e o tamanho de uma fonte para descrever a fonte lógica. Se uma fonte com o nome especificado não existir, uma fonte de qualquer conjunto de caracteres pode ser substituída para a fonte especificada. Para evitar resultados inesperados, os aplicativos devem usar o `DEFAULT_CHARSET` valor com moderação.  
  
 `nOutPrecision`  
 Especifica a precisão de saída desejada. A precisão de saída define proximidade a saída deve corresponder a fonte solicitada altura, largura, orientação de caracteres, escape e densidade. Consulte o `lfOutPrecision` membro o `LOGFONT` estrutura no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)] para obter uma lista de valores e obter mais informações.  
  
 `nClipPrecision`  
 Especifica a precisão de recorte desejado. A precisão de recorte define como cortar caracteres que são parcialmente fora da região de recorte. Consulte o `lfClipPrecision` membro o `LOGFONT` estrutura no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)] para obter uma lista de valores.  
  
 Para usar uma fonte incorporada somente leitura, um aplicativo deve especificar `CLIP_ENCAPSULATE`.  
  
 Para obter a rotação consistente de dispositivo, TrueType e fontes vetoriais, um aplicativo pode usar o operador OR para combinar o `CLIP_LH_ANGLES` valor com quaisquer outras `nClipPrecision` valores. Se o `CLIP_LH_ANGLES` bit estiver definido, a rotação de todas as fontes depende se a orientação do sistema de coordenadas é canhoto ou destro. (Para obter mais informações sobre a orientação dos sistemas de coordenadas, consulte a descrição do `nOrientation` parâmetro.) Se `CLIP_LH_ANGLES` não é definido, fontes de dispositivo sempre girar no sentido anti-horário, mas a rotação de outras fontes depende da orientação do sistema de coordenadas.  
  
 `nQuality`  
 Especifica a qualidade de saída da fonte, que define como cuidadosamente a GDI deve tentar corresponder os atributos de fonte lógico para aqueles de uma fonte física real. Consulte o `lfQuality` membro o `LOGFONT` estrutura no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)] para obter uma lista de valores.  
  
 `nPitchAndFamily`  
 Especifica a densidade e a família da fonte. Consulte o `lfPitchAndFamily` membro o `LOGFONT` estrutura no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)] para obter uma lista de valores e obter mais informações.  
  
 `lpszFacename`  
 Um `CString` ou um ponteiro para uma cadeia de caracteres terminada em nulo que especifica o nome de face da fonte. O comprimento da cadeia de caracteres não deve exceder 30 caracteres. O Windows [EnumFontFamilies](http://msdn.microsoft.com/library/windows/desktop/dd162619) função pode ser usada para enumerar todas as fontes disponíveis no momento. Se `lpszFacename` é `NULL`, a GDI usa uma fonte independente de dispositivo.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 A fonte posteriormente pode ser selecionada como a fonte para qualquer contexto de dispositivo.  
  
 O `CreateFont` função não cria uma nova fonte de GDI do Windows. Seleciona apenas a correspondência mais próxima do físicas fontes disponíveis para a GDI.  
  
 Aplicativos podem usar as configurações padrão para a maioria dos parâmetros ao criar uma fonte de lógica. Os parâmetros que sempre devem receber valores específicos são `nHeight` e `lpszFacename`. Se `nHeight` e `lpszFacename` não são definidas pelo aplicativo, a fonte lógica que é criada depende do dispositivo.  
  
 Quando você terminar com a `CFont` objeto criado pelo `CreateFont` função, use `CDC::SelectObject` para selecionar uma fonte diferente para o contexto de dispositivo, em seguida, exclua o `CFont` objeto não for mais necessário.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView&#71;](../../mfc/codesnippet/cpp/cfont-class_2.cpp)]  
  
##  <a name="a-namecreatefontindirecta--cfontcreatefontindirect"></a><a name="createfontindirect"></a>CFont::CreateFontIndirect  
 Inicializa uma `CFont` objeto com as características fornecido em uma [LOGFONT](http://msdn.microsoft.com/library/windows/desktop/dd145037)estrutura.  
  
```  
BOOL CreateFontIndirect(const LOGFONT* lpLogFont);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpLogFont`  
 Aponta para um `LOGFONT` estrutura que define as características da fonte lógica.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 A fonte posteriormente pode ser selecionada como a fonte atual para qualquer dispositivo.  
  
 Essa fonte tem as características especificadas no [LOGFONT](http://msdn.microsoft.com/library/windows/desktop/dd145037) estrutura. Quando a fonte é selecionada usando o [CDC::SelectObject](../../mfc/reference/cdc-class.md#selectobject) função de membro, o mapeador de fonte GDI tenta corresponder a fonte lógica com uma fonte física existente. O mapeador de fonte não conseguir localizar uma correspondência exata para a fonte lógica, ele fornece uma fonte alternativa cujas características correspondem como muitas das características solicitadas quanto possível.  
  
 Quando você não precisa mais o `CFont` objeto criado pelo `CreateFontIndirect` função, use `CDC::SelectObject` para selecionar uma fonte diferente para o contexto de dispositivo, em seguida, exclua o `CFont` objeto não for mais necessário.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView&#72;](../../mfc/codesnippet/cpp/cfont-class_3.cpp)]  
  
##  <a name="a-namecreatepointfonta--cfontcreatepointfont"></a><a name="createpointfont"></a>CFont::CreatePointFont  
 Essa função fornece uma maneira simples de criar uma fonte de tipos especificada e o tamanho.  
  
```  
BOOL CreatePointFont(
    int nPointSize,  
    LPCTSTR lpszFaceName,  
    CDC* pDC = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nPointSize`  
 Solicitou a altura da fonte em décimos de um ponto. (Por exemplo, passar 120 para solicitar uma fonte de 12 pontos).  
  
 `lpszFaceName`  
 Um `CString` ou um ponteiro para uma cadeia de caracteres terminada em nulo que especifica o nome de face da fonte. O comprimento da cadeia de caracteres não deve exceder 30 caracteres. O Windows **EnumFontFamilies** função pode ser usada para enumerar todas as fontes disponíveis no momento. Se `lpszFaceName` é **nulo**, a GDI usa uma fonte independente de dispositivo.  
  
 `pDC`  
 Ponteiro para o [CDC](../../mfc/reference/cdc-class.md) objeto a ser usado para converter a altura em `nPointSize` unidades lógicas. Se **nulo**, um contexto de dispositivo da tela é usado para a conversão.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se tiver êxito, caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Ele converte automaticamente a altura em `nPointSize` unidades lógicas usando o `CDC` objeto apontado por `pDC`.  
  
 Quando você terminar com a `CFont` objeto criado pelo `CreatePointFont` funcionar, primeiro selecione a fonte fora do contexto de dispositivo, excluir o `CFont` objeto.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView&#73;](../../mfc/codesnippet/cpp/cfont-class_4.cpp)]  
  
##  <a name="a-namecreatepointfontindirecta--cfontcreatepointfontindirect"></a><a name="createpointfontindirect"></a>CFont::CreatePointFontIndirect  
 Essa função é o mesmo que [CreateFontIndirect](#createfontindirect) exceto que o **lfHeight** membro do `LOGFONT` é interpretado em décimos de unidades de um ponto em vez de dispositivo.  
  
```  
BOOL CreatePointFontIndirect(
    const LOGFONT* lpLogFont,  
    CDC* pDC = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpLogFont`  
 Aponta para um [LOGFONT](http://msdn.microsoft.com/library/windows/desktop/dd145037) estrutura que define as características da fonte lógica. O **lfHeight** membro o `LOGFONT` estrutura é medida em décimos de um ponto em vez de unidades lógicas. (Por exemplo, definir **lfHeight** para 120 para solicitar uma fonte de 12 pontos.)  
  
 `pDC`  
 Ponteiro para o [CDC](../../mfc/reference/cdc-class.md) objeto a ser usado para converter a altura em **lfHeight** unidades lógicas. Se **nulo**, um contexto de dispositivo da tela é usado para a conversão.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se tiver êxito, caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Esta função converte automaticamente a altura em **lfHeight** unidades lógicas usando o `CDC` objeto apontado por `pDC` antes de passar o `LOGFONT` estrutura no Windows.  
  
 Quando você terminar com a `CFont` objeto criado pelo `CreatePointFontIndirect` funcionar, primeiro selecione a fonte fora do contexto de dispositivo, excluir o `CFont` objeto.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView&#74;](../../mfc/codesnippet/cpp/cfont-class_5.cpp)]  
  
##  <a name="a-namefromhandlea--cfontfromhandle"></a><a name="fromhandle"></a>CFont::FromHandle  
 Retorna um ponteiro para um `CFont` objeto quando é fornecido um **HFONT** identificador de um objeto de fonte GDI do Windows.  
  
```  
static CFont* PASCAL FromHandle(HFONT hFont);
```  
  
### <a name="parameters"></a>Parâmetros  
 `hFont`  
 Um **HFONT** identificador para uma fonte do Windows.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para um `CFont` objeto se bem-sucedido; caso contrário **nulo**.  
  
### <a name="remarks"></a>Comentários  
 Se um `CFont` objeto já não está anexado ao identificador, um temporário `CFont` objeto é criado e anexado. Esse temporário `CFont` objeto é válido somente até a próxima vez que o aplicativo tiver tempo ocioso em seu loop de evento, em que ponto gráfico temporário todos os objetos são excluídos. Outra maneira de dizer isso é que o objeto temporário é válido somente durante o processamento da mensagem de uma janela.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView&#75;](../../mfc/codesnippet/cpp/cfont-class_6.cpp)]  
  
##  <a name="a-namegetlogfonta--cfontgetlogfont"></a><a name="getlogfont"></a>CFont::GetLogFont  
 Chame essa função para recuperar uma cópia do `LOGFONT` estrutura `CFont`.  
  
```  
int GetLogFont(LOGFONT* pLogFont);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pLogFont*  
 Ponteiro para o [LOGFONT](http://msdn.microsoft.com/library/windows/desktop/dd145037) estrutura para receber as informações de fonte.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a função obtiver êxito, caso contrário, 0.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView&#76;](../../mfc/codesnippet/cpp/cfont-class_7.cpp)]  
  
##  <a name="a-nameoperatorhfonta--cfontoperator-hfont"></a><a name="operator_hfont"></a>CFont::operator HFONT  
 Usar esse operador para obter o identificador da GDI do Windows da fonte anexado para o `CFont` objeto.  
  
```  
operator HFONT() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O identificador do objeto de fonte GDI do Windows conectado ao `CFont` se bem-sucedido; caso contrário **nulo**.  
  
### <a name="remarks"></a>Comentários  
 Como esse operador automaticamente é usado para conversões de `CFont` para [fontes e texto](http://msdn.microsoft.com/library/windows/desktop/dd144819), você pode passar `CFont` objetos para funções que esperam **HFONT**s.  
  
 Para obter mais informações sobre como usar objetos gráficos, consulte [objetos de gráfico](http://msdn.microsoft.com/library/windows/desktop/dd144962) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView&#77;](../../mfc/codesnippet/cpp/cfont-class_8.cpp)]  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo MFC HIERSVR](../../visual-cpp-samples.md)   
 [Classe CGdiObject](../../mfc/reference/cgdiobject-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)




