---
title: Classe CFont | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CFont
- AFXWIN/CFont
- AFXWIN/CFont::CFont
- AFXWIN/CFont::CreateFont
- AFXWIN/CFont::CreateFontIndirect
- AFXWIN/CFont::CreatePointFont
- AFXWIN/CFont::CreatePointFontIndirect
- AFXWIN/CFont::FromHandle
- AFXWIN/CFont::GetLogFont
dev_langs:
- C++
helpviewer_keywords:
- CFont [MFC], CFont
- CFont [MFC], CreateFont
- CFont [MFC], CreateFontIndirect
- CFont [MFC], CreatePointFont
- CFont [MFC], CreatePointFontIndirect
- CFont [MFC], FromHandle
- CFont [MFC], GetLogFont
ms.assetid: 3fad6bfe-d6ce-4ab9-967a-5ce0aa102800
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 5431461c7c2cc33131f72f059edcfbd984eae5fb
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="cfont-class"></a>Classe CFont
Encapsula uma fonte de interface (GDI) do dispositivo de gráficos Windows e fornece funções de membro para manipular a fonte.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CFont : public CGdiObject  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CFont::CFont](#cfont)|Constrói um objeto `CFont`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CFont::CreateFont](#createfont)|Inicializa um `CFont` com as características especificadas.|  
|[CFont::CreateFontIndirect](#createfontindirect)|Inicializa um `CFont` objeto com as características fornecido em um `LOGFONT` estrutura.|  
|[CFont::CreatePointFont](#createpointfont)|Inicializa um `CFont` com a altura especificada, medida em décimos de um ponto e o tipo de fonte.|  
|[CFont::CreatePointFontIndirect](#createpointfontindirect)|Mesmo que `CreateFontIndirect` exceto que a altura da fonte é medida em décimos de um ponto, em vez de unidades lógicas.|  
|[CFont::FromHandle](#fromhandle)|Retorna um ponteiro para um `CFont` objeto quando é fornecido um Windows **HFONT**.|  
|[CFont::GetLogFont](#getlogfont)|Preenche uma `LOGFONT` com informações sobre a fonte lógica anexada para o `CFont` objeto.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CFont::operator HFONT](#operator_hfont)|Retorna o identificador de fonte GDI Windows anexado para o `CFont` objeto.|  
  
## <a name="remarks"></a>Comentários  
 Para usar um `CFont` do objeto, construa um `CFont` de objeto e anexar uma fonte do Windows com [CreateFont](#createfont), [CreateFontIndirect](#createfontindirect), [CreatePointFont](#createpointfont), ou [CreatePointFontIndirect](#createpointfontindirect)e, em seguida, usar funções de membro do objeto para manipular a fonte.  
  
 O `CreatePointFont` e `CreatePointFontIndirect` funções geralmente são mais fáceis de usar que `CreateFont` ou `CreateFontIndirect` desde que eles fazem a conversão para a altura da fonte de um tamanho de ponto para unidades lógicas automaticamente.  
  
 Para obter mais informações sobre `CFont`, consulte [objetos gráficos](../../mfc/graphic-objects.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CGdiObject](../../mfc/reference/cgdiobject-class.md)  
  
 `CFont`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxwin.h  
  
##  <a name="cfont"></a>CFont::CFont  
 Constrói um objeto `CFont`.  
  
```  
CFont();
```  
  
### <a name="remarks"></a>Comentários  
 O objeto resultante deve ser inicializado com `CreateFont`, `CreateFontIndirect`, `CreatePointFont`, ou `CreatePointFontIndirect` antes de ser usada.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView#70](../../mfc/codesnippet/cpp/cfont-class_1.cpp)]  
  
##  <a name="createfont"></a>CFont::CreateFont  
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
 Especifica a altura desejada (em unidades lógicas) da fonte. Consulte o `lfHeight` membro o [LOGFONT](http://msdn.microsoft.com/library/windows/desktop/dd145037)estrutura no SDK do Windows para obter uma descrição. O valor absoluto de `nHeight` não deve exceder 16.384 unidades de dispositivo depois de ser convertido. Para todas as comparações de altura, o mapeador de fonte procura a maior fonte que não exceda o tamanho solicitado ou a fonte menor se todas as fontes excederem o tamanho solicitado.  
  
 `nWidth`  
 Especifica a largura média (em unidades lógicas) de caracteres na fonte. Se `nWidth` for 0, a taxa de proporção do dispositivo será comparada com a taxa de proporção de digitalização das fontes disponíveis para localizar a correspondência mais próxima, que é determinada pelo valor absoluto da diferença.  
  
 `nEscapement`  
 Especifica o ângulo (em unidades de 0,1 grau) entre o vetor de escape e o eixo x da superfície de exibição. O vetor de escape é a linha até as origens do primeiro e último caracteres em uma linha. O ângulo é medido no sentido anti-horário do eixo x. Consulte o `lfEscapement` membro o `LOGFONT` estrutura no SDK do Windows para obter mais informações.  
  
 `nOrientation`  
 Especifica o ângulo (em unidades de 0,1 grau) entre a linha de base de um caractere e o eixo x. O ângulo é medido no sentido anti-horário do eixo x para sistemas de coordenadas no qual a direção de y é sentido anti-horário do eixo x para sistemas de coordenadas no qual a direção de y é para cima e para baixo.  
  
 `nWeight`  
 Especifica a espessura da fonte (em pixels coloridos por 1000). Consulte o `lfWeight` membro o `LOGFONT` estrutura no SDK do Windows para obter mais informações. Os valores descritos são aproximados; a aparência real depende da face de tipos. Algumas fontes têm apenas `FW_NORMAL`, `FW_REGULAR`, e `FW_BOLD` pesos. Se `FW_DONTCARE` for especificado, um peso padrão será usado.  
  
 `bItalic`  
 Especifica se a fonte está em itálico.  
  
 `bUnderline`  
 Especifica se a fonte está sublinhada.  
  
 `cStrikeOut`  
 Especifica se os caracteres na fonte são riscados. Especifica uma fonte riscado se definido como um valor diferente de zero.  
  
 `nCharSet`  
 Especifica setSee de caractere da fonte de `lfCharSet` membro o `LOGFONT` estrutura no SDK do Windows para obter uma lista de valores.  
  
 O conjunto de caracteres OEM é dependente do sistema.  
  
 Fontes com outros conjuntos de caracteres podem existir no sistema. Um aplicativo que usa uma fonte com um conjunto de caracteres desconhecido não deve tentar converter ou interpretar cadeias de caracteres a ser renderizado com essa fonte. Em vez disso, as cadeias de caracteres devem ser passadas diretamente para o driver de dispositivo de saída.  
  
 O mapeador de fonte não usa o `DEFAULT_CHARSET` valor. Um aplicativo pode usar esse valor para permitir que o nome e o tamanho de uma fonte para descrever a fonte lógica. Se uma fonte com o nome especificado não existir, uma fonte de qualquer conjunto de caracteres pode ser substituída para a fonte especificada. Para evitar resultados inesperados, os aplicativos devem usar o `DEFAULT_CHARSET` valor com moderação.  
  
 `nOutPrecision`  
 Especifica a precisão de saída desejada. A precisão de saída define a exatidão com a saída deve corresponder a fonte solicitada altura, largura, orientação de caractere, escape e tom. Consulte o `lfOutPrecision` membro o `LOGFONT` estrutura no SDK do Windows para obter uma lista de valores e obter mais informações.  
  
 `nClipPrecision`  
 Especifica a precisão de recorte desejado. A precisão de recorte define como cortar caracteres que são parcialmente fora da região de recorte. Consulte o `lfClipPrecision` membro o `LOGFONT` estrutura no SDK do Windows para obter uma lista de valores.  
  
 Para usar uma fonte incorporada somente leitura, um aplicativo deve especificar `CLIP_ENCAPSULATE`.  
  
 Para obter a rotação consistente de dispositivo, TrueType e fontes de vetor, um aplicativo pode usar o operador OR para combinar o `CLIP_LH_ANGLES` valor com qualquer dos outros `nClipPrecision` valores. Se o `CLIP_LH_ANGLES` bit é definido, a rotação de todas as fontes depende se a orientação do sistema de coordenadas é canhoto ou direita. (Para obter mais informações sobre a orientação de sistemas de coordenadas, consulte a descrição do `nOrientation` parâmetro.) Se `CLIP_LH_ANGLES` não é definido, fontes de dispositivo sempre girar no sentido anti-horário, mas a rotação de outras fontes depende da orientação do sistema de coordenadas.  
  
 `nQuality`  
 Especifica a qualidade de saída da fonte, que define como cuidadosamente o GDI deve tentar corresponder os atributos de fonte lógico de uma fonte física real. Consulte o `lfQuality` membro o `LOGFONT` estrutura no SDK do Windows para obter uma lista de valores.  
  
 `nPitchAndFamily`  
 Especifica a densidade e a família da fonte. Consulte o `lfPitchAndFamily` membro o `LOGFONT` estrutura no SDK do Windows para obter uma lista de valores e obter mais informações.  
  
 `lpszFacename`  
 Um `CString` ou ponteiro para uma cadeia de caracteres terminada em nulo que especifica o nome do tipo da fonte. O comprimento da cadeia de caracteres não deve exceder 30 caracteres. O Windows [EnumFontFamilies](http://msdn.microsoft.com/library/windows/desktop/dd162619) função pode ser usada para enumerar todas as fontes disponíveis no momento. Se `lpszFacename` é `NULL`, a GDI usa uma fonte independente de dispositivo.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 A fonte posteriormente pode ser selecionada como fonte para qualquer contexto de dispositivo.  
  
 O `CreateFont` função não cria uma nova fonte GDI do Windows. Seleciona apenas a correspondência mais próxima do físicas fontes disponíveis para o GDI.  
  
 Aplicativos podem usar as configurações padrão para a maioria dos parâmetros ao criar uma fonte de lógica. Os parâmetros que sempre devem ser dadas valores específicos são `nHeight` e `lpszFacename`. Se `nHeight` e `lpszFacename` não são definidas pelo aplicativo, a fonte lógica que é criada depende do dispositivo.  
  
 Quando você terminar com a `CFont` objeto criado pelo `CreateFont` função, use `CDC::SelectObject` para selecionar uma fonte diferente no contexto de dispositivo, em seguida, exclua o `CFont` objeto não for mais necessário.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView#71](../../mfc/codesnippet/cpp/cfont-class_2.cpp)]  
  
##  <a name="createfontindirect"></a>CFont::CreateFontIndirect  
 Inicializa um `CFont` objeto com as características fornecido em um [LOGFONT](http://msdn.microsoft.com/library/windows/desktop/dd145037)estrutura.  
  
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
  
 Essa fonte tem as características especificadas no [LOGFONT](http://msdn.microsoft.com/library/windows/desktop/dd145037) estrutura. Quando a fonte é selecionada usando o [CDC::SelectObject](../../mfc/reference/cdc-class.md#selectobject) função de membro, o mapeador de fonte GDI tenta corresponder a fonte lógica com uma fonte física existente. Se o mapeador de fonte não conseguir localizar uma correspondência exata para a fonte lógica, ele fornece uma fonte alternativa cujas características correspondem como muitas das características solicitadas quanto possível.  
  
 Quando você não precisa mais o `CFont` objeto criado pelo `CreateFontIndirect` função, use `CDC::SelectObject` para selecionar uma fonte diferente no contexto de dispositivo, em seguida, exclua o `CFont` objeto não for mais necessário.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView#72](../../mfc/codesnippet/cpp/cfont-class_3.cpp)]  
  
##  <a name="createpointfont"></a>CFont::CreatePointFont  
 Essa função fornece uma maneira simples de criar uma fonte de um tipo especificado e o tamanho do ponto.  
  
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
 Um `CString` ou ponteiro para uma cadeia de caracteres terminada em nulo que especifica o nome do tipo da fonte. O comprimento da cadeia de caracteres não deve exceder 30 caracteres. O Windows **EnumFontFamilies** função pode ser usada para enumerar todas as fontes disponíveis no momento. Se `lpszFaceName` é **nulo**, a GDI usa uma fonte independente de dispositivo.  
  
 `pDC`  
 Ponteiro para o [CDC](../../mfc/reference/cdc-class.md) objeto a ser usado para converter a altura em `nPointSize` para unidades lógicas. Se **nulo**, um contexto de dispositivo de tela é usado para a conversão.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedido, caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Ele converte automaticamente a altura em `nPointSize` para unidades lógicas usando o `CDC` objeto apontada pelo `pDC`.  
  
 Quando você terminar com a `CFont` objeto criado pelo `CreatePointFont` funcionar, primeiro selecione a fonte fora do contexto de dispositivo, e depois exclua a `CFont` objeto.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView#73](../../mfc/codesnippet/cpp/cfont-class_4.cpp)]  
  
##  <a name="createpointfontindirect"></a>CFont::CreatePointFontIndirect  
 Essa função é o mesmo que [CreateFontIndirect](#createfontindirect) exceto que o **lfHeight** membro o `LOGFONT` é interpretado em décimos de unidades de um ponto em vez de um dispositivo.  
  
```  
BOOL CreatePointFontIndirect(
    const LOGFONT* lpLogFont,  
    CDC* pDC = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpLogFont`  
 Aponta para um [LOGFONT](http://msdn.microsoft.com/library/windows/desktop/dd145037) estrutura que define as características da fonte lógica. O **lfHeight** membro o `LOGFONT` estrutura é medida em décimos de um ponto, em vez de unidades lógicas. (Por exemplo, definir **lfHeight** para 120 para solicitar uma fonte de 12 pontos.)  
  
 `pDC`  
 Ponteiro para o [CDC](../../mfc/reference/cdc-class.md) objeto a ser usado para converter a altura em **lfHeight** para unidades lógicas. Se **nulo**, um contexto de dispositivo de tela é usado para a conversão.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedido, caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Esta função converte automaticamente a altura em **lfHeight** para unidades lógicas usando o `CDC` objeto apontada pelo `pDC` antes de passar o `LOGFONT` estrutura de logon no Windows.  
  
 Quando você terminar com a `CFont` objeto criado pelo `CreatePointFontIndirect` funcionar, primeiro selecione a fonte fora do contexto de dispositivo, e depois exclua a `CFont` objeto.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView#74](../../mfc/codesnippet/cpp/cfont-class_5.cpp)]  
  
##  <a name="fromhandle"></a>CFont::FromHandle  
 Retorna um ponteiro para um `CFont` objeto quando é fornecido um **HFONT** identificador para um objeto de fonte GDI do Windows.  
  
```  
static CFont* PASCAL FromHandle(HFONT hFont);
```  
  
### <a name="parameters"></a>Parâmetros  
 `hFont`  
 Um **HFONT** identificador para uma fonte do Windows.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para um `CFont` objeto se for bem-sucedida; caso contrário **nulo**.  
  
### <a name="remarks"></a>Comentários  
 Se um `CFont` objeto já não está anexado para o identificador de um temporário `CFont` objeto é criado e anexado. Este temporário `CFont` objeto é válido somente até a próxima vez que o aplicativo tem tempo ocioso em seu loop de evento, em que ponto o gráfico temporário todos os objetos serão excluídos. Outra maneira de dizer isso é que o objeto temporário é válido somente durante o processamento da mensagem de uma janela.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView#75](../../mfc/codesnippet/cpp/cfont-class_6.cpp)]  
  
##  <a name="getlogfont"></a>CFont::GetLogFont  
 Chamar essa função para recuperar uma cópia do `LOGFONT` estrutura `CFont`.  
  
```  
int GetLogFont(LOGFONT* pLogFont);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pLogFont*  
 Ponteiro para o [LOGFONT](http://msdn.microsoft.com/library/windows/desktop/dd145037) estrutura para receber as informações de fonte.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a função tiver êxito, caso contrário, 0.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView#76](../../mfc/codesnippet/cpp/cfont-class_7.cpp)]  
  
##  <a name="operator_hfont"></a>CFont::operator HFONT  
 Use este operador para obter o identificador do Windows GDI da fonte anexado para o `CFont` objeto.  
  
```  
operator HFONT() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O identificador do objeto de fonte GDI Windows anexado ao `CFont` se bem-sucedido; caso contrário **nulo**.  
  
### <a name="remarks"></a>Comentários  
 Como esse operador é usado automaticamente para conversões de `CFont` para [fontes e texto](http://msdn.microsoft.com/library/windows/desktop/dd144819), você pode passar `CFont` objetos para funções que esperam **HFONT**s.  
  
 Para obter mais informações sobre como usar objetos gráficos, consulte [objetos de gráfico](http://msdn.microsoft.com/library/windows/desktop/dd144962) no SDK do Windows.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView#77](../../mfc/codesnippet/cpp/cfont-class_8.cpp)]  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo MFC HIERSVR](../../visual-cpp-samples.md)   
 [Classe CGdiObject](../../mfc/reference/cgdiobject-class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)



