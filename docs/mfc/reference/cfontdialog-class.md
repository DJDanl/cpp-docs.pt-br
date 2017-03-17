---
title: Classe CFontDialog | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CFontDialog
- AFXDLGS/CFontDialog
- AFXDLGS/CFontDialog::CFontDialog
- AFXDLGS/CFontDialog::DoModal
- AFXDLGS/CFontDialog::GetCharFormat
- AFXDLGS/CFontDialog::GetColor
- AFXDLGS/CFontDialog::GetCurrentFont
- AFXDLGS/CFontDialog::GetFaceName
- AFXDLGS/CFontDialog::GetSize
- AFXDLGS/CFontDialog::GetStyleName
- AFXDLGS/CFontDialog::GetWeight
- AFXDLGS/CFontDialog::IsBold
- AFXDLGS/CFontDialog::IsItalic
- AFXDLGS/CFontDialog::IsStrikeOut
- AFXDLGS/CFontDialog::IsUnderline
- AFXDLGS/CFontDialog::m_cf
dev_langs:
- C++
helpviewer_keywords:
- CFontDialog class
- dialog boxes, fonts
- fonts
- fonts, selecting
ms.assetid: 6228d500-ed0f-4156-81e5-ab0d57d1dcf4
caps.latest.revision: 25
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
ms.openlocfilehash: 6f277ba8fba72106918e03397f57726bd5beb0ff
ms.lasthandoff: 02/25/2017

---
# <a name="cfontdialog-class"></a>Classe CFontDialog
Permite incorporar uma caixa de diálogo de seleção de fonte em seu aplicativo.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CFontDialog : public CCommonDialog  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CFontDialog::CFontDialog](#cfontdialog)|Constrói um objeto `CFontDialog`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CFontDialog::DoModal](#domodal)|Exibe a caixa de diálogo e permite que o usuário faça uma seleção.|  
|[CFontDialog::GetCharFormat](#getcharformat)|Recupera a formatação de caractere da fonte selecionada.|  
|[CFontDialog::GetColor](#getcolor)|Retorna a cor da fonte selecionada.|  
|[CFontDialog::GetCurrentFont](#getcurrentfont)|Atribui as características da fonte selecionada no momento para um `LOGFONT` estrutura.|  
|[CFontDialog::GetFaceName](#getfacename)|Retorna o nome de face da fonte selecionada.|  
|[CFontDialog::GetSize](#getsize)|Retorna o tamanho da fonte selecionada.|  
|[CFontDialog::GetStyleName](#getstylename)|Retorna o nome do estilo da fonte selecionada.|  
|[CFontDialog::GetWeight](#getweight)|Retorna o peso da fonte selecionada.|  
|[CFontDialog::IsBold](#isbold)|Determina se a fonte está em negrito.|  
|[CFontDialog::IsItalic](#isitalic)|Determina se a fonte está em itálico.|  
|[CFontDialog::IsStrikeOut](#isstrikeout)|Determina se a fonte é exibida com riscado.|  
|[CFontDialog::IsUnderline](#isunderline)|Determina se a fonte é sublinhada.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CFontDialog::m_cf](#m_cf)|Uma estrutura usada para personalizar um `CFontDialog` objeto.|  
  
## <a name="remarks"></a>Comentários  
 Um `CFontDialog` objeto é uma caixa de diálogo com uma lista de fontes que estão atualmente instalados no sistema. O usuário pode selecionar uma fonte específica na lista, e essa seleção, em seguida, é relatada de volta para o aplicativo.  
  
 Para construir um `CFontDialog` do objeto, use o construtor fornecido ou derivar uma nova subclasse e usar seu próprio construtor personalizado.  
  
 Uma vez um `CFontDialog` objeto foi construído, você pode usar o `m_cf` estrutura para inicializar os valores ou os estados de controles na caixa de diálogo. O [m_cf](#m_cf) estrutura é do tipo [CHOOSEFONT](http://msdn.microsoft.com/library/windows/desktop/ms646832). Para obter mais informações sobre essa estrutura, consulte o [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
 Após inicializar controles da caixa de diálogo objeto, chame o `DoModal` a função de membro para exibir a caixa de diálogo e permitir que o usuário selecione uma fonte. `DoModal`Retorna se o usuário selecionou o Okey ( **IDOK**) ou Cancel ( **IDCANCEL**) botão.  
  
 Se `DoModal` retorna **IDOK**, você pode usar um dos `CFontDialog`de funções de membro para recuperar as informações de entrada do usuário.  
  
 Você pode usar o Windows [CommDlgExtendedError](http://msdn.microsoft.com/library/windows/desktop/ms646916) função para determinar se ocorreu um erro durante a inicialização da caixa de diálogo e saiba mais sobre o erro. Para obter mais informações sobre essa função, consulte o [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
 `CFontDialog`depende do COMMDLG. Arquivo DLL que acompanha o Windows versões 3.1 e posteriores.  
  
 Para personalizar a caixa de diálogo, derive uma classe de `CFontDialog`, fornecer um modelo de caixa de diálogo personalizada e adicionar um mapa de mensagem para processar as mensagens de notificação de controles estendidos. Todas as mensagens não processadas devem ser passadas para a classe base.  
  
 Personalizando a função de gancho não é necessária.  
  
 Para obter mais informações sobre como usar o `CFontDialog`, consulte [Classes comuns do diálogo](../../mfc/common-dialog-classes.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 [CDialog](../../mfc/reference/cdialog-class.md)  
  
 [CCommonDialog](../../mfc/reference/ccommondialog-class.md)  
  
 `CFontDialog`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxdlgs. h  
  
##  <a name="cfontdialog"></a>CFontDialog::CFontDialog  
 Constrói um objeto `CFontDialog`.  
  
```  
CFontDialog(
    LPLOGFONT lplfInitial = NULL,  
    DWORD dwFlags = CF_EFFECTS | CF_SCREENFONTS,  
    CDC* pdcPrinter = NULL,  
    CWnd* pParentWnd = NULL);

CFontDialog(
    const CHARFORMAT& charformat,  
    DWORD dwFlags = CF_SCREENFONTS,  
    CDC* pdcPrinter = NULL,  
    CWnd* pParentWnd = NULL);  
```  
  
### <a name="parameters"></a>Parâmetros  
 l`plfInitial`  
 Um ponteiro para um [LOGFONT](http://msdn.microsoft.com/library/windows/desktop/dd145037) estrutura de dados que permite que você defina algumas das características da fonte.  
  
 `charFormat`  
 Um ponteiro para um [CHARFORMAT](http://msdn.microsoft.com/library/windows/desktop/bb787881) controle de edição de estrutura de dados que permite que você defina algumas das características da fonte em uma rica.  
  
 `dwFlags`  
 Especifica um ou mais sinalizadores de escolha de fonte. Um ou mais valores predefinidos podem ser combinados usando o operador bit a bit OR. Se você modificar o membro da estrutura `m_cf.Flag`, certifique-se de usar um operador bit a bit OR em suas alterações para manter o comportamento padrão intacto. Para obter detalhes sobre cada um desses sinalizadores, consulte a descrição do [CHOOSEFONT](http://msdn.microsoft.com/library/windows/desktop/ms646832) estrutura no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
 pdcPrinter  
 Um ponteiro para um contexto de dispositivo de impressão. Se fornecido, esse parâmetro apontará para um contexto de dispositivo de impressão para a impressora na qual as fontes serão selecionadas.  
  
 `pParentWnd`  
 Um ponteiro para a janela pai ou proprietária da caixa de diálogo da fonte.  
  
### <a name="remarks"></a>Comentários  
 Observe que o construtor preenche automaticamente os membros da estrutura `CHOOSEFONT`. Você só deve alterar isso se quiser um diálogo de fonte diferente do padrão.  
  
> [!NOTE]
>  A primeira versão dessa função só existe quando não há suporte para controle de edição com formato.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView&#78;](../../mfc/codesnippet/cpp/cfontdialog-class_1.cpp)]  
  
##  <a name="domodal"></a>CFontDialog::DoModal  
 Chame essa função para exibir a caixa de diálogo de fonte comuns do Windows e permitir que o usuário escolha uma fonte.  
  
```  
virtual INT_PTR DoModal();
```  
  
### <a name="return-value"></a>Valor de retorno  
 **IDOK** ou **IDCANCEL**. Se **IDCANCEL** é retornado, chame o Windows [CommDlgExtendedError](http://msdn.microsoft.com/library/windows/desktop/ms646916) função para determinar se ocorreu um erro.  
  
 **IDOK** e **IDCANCEL** são constantes que indicam se o usuário selecionou o botão Okey ou Cancelar.  
  
### <a name="remarks"></a>Comentários  
 Se você quiser inicializar os vários controles de caixa de diálogo fonte definindo membros do [m_cf](#m_cf) estrutura, você deve fazer isso antes de chamar `DoModal`, mas depois que o objeto de caixa de diálogo é construído.  
  
 Se `DoModal` retorna **IDOK**, você pode chamar outro membro funções para recuperar as configurações ou entrada de informações pelo usuário na caixa de diálogo.  
  
### <a name="example"></a>Exemplo  
  Consulte os exemplos de [CFontDialog::CFontDialog](#cfontdialog) e [CFontDialog::GetColor](#getcolor).  
  
##  <a name="getcharformat"></a>CFontDialog::GetCharFormat  
 Recupera a formatação de caractere da fonte selecionada.  
  
```  
void GetCharFormat(CHARFORMAT& cf) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `cf`  
 A [CHARFORMAT](http://msdn.microsoft.com/library/windows/desktop/bb787881) estrutura que contém informações sobre a formatação de caractere da fonte selecionada.  
  
##  <a name="getcolor"></a>CFontDialog::GetColor  
 Chame essa função para recuperar a cor da fonte selecionada.  
  
```  
COLORREF GetColor() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 A cor da fonte selecionada.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView&#79;](../../mfc/codesnippet/cpp/cfontdialog-class_2.cpp)]  
  
##  <a name="getcurrentfont"></a>CFontDialog::GetCurrentFont  
 Chame essa função para atribuir as características da fonte selecionada no momento para os membros de um [LOGFONT](http://msdn.microsoft.com/library/windows/desktop/dd145037) estrutura.  
  
```  
void GetCurrentFont(LPLOGFONT lplf);
```  
  
### <a name="parameters"></a>Parâmetros  
 *lplf*  
 Um ponteiro para um `LOGFONT` estrutura.  
  
### <a name="remarks"></a>Comentários  
 Outros `CFontDialog` funções de membro são fornecidas para acessar as características individuais da fonte atual.  
  
 Se essa função é chamada durante uma chamada para [DoModal](#domodal), retorna a seleção atual no momento (o que o usuário vê ou foi alterada na caixa de diálogo). Se essa função é chamada após uma chamada para `DoModal` (somente se `DoModal` retorna **IDOK**), ele retorna o que o usuário realmente selecionado.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView&#80;](../../mfc/codesnippet/cpp/cfontdialog-class_3.cpp)]  
  
##  <a name="getfacename"></a>CFontDialog::GetFaceName  
 Chame essa função para recuperar o nome de face da fonte selecionada.  
  
```  
CString GetFaceName() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O nome de face da fonte selecionada no `CFontDialog` caixa de diálogo.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView&#81;](../../mfc/codesnippet/cpp/cfontdialog-class_4.cpp)]  
  
##  <a name="getsize"></a>CFontDialog::GetSize  
 Chame essa função para recuperar o tamanho da fonte selecionada.  
  
```  
int GetSize() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Tamanho da fonte, em décimos de um ponto.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView&#82;](../../mfc/codesnippet/cpp/cfontdialog-class_5.cpp)]  
  
##  <a name="getstylename"></a>CFontDialog::GetStyleName  
 Chame essa função para recuperar o nome do estilo da fonte selecionada.  
  
```  
CString GetStyleName() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O nome do estilo da fonte.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView&#83;](../../mfc/codesnippet/cpp/cfontdialog-class_6.cpp)]  
  
##  <a name="getweight"></a>CFontDialog::GetWeight  
 Chame essa função para recuperar o peso da fonte selecionada.  
  
```  
int GetWeight() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 A espessura da fonte selecionada.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações sobre o peso de uma fonte, consulte [CFont::CreateFont](../../mfc/reference/cfont-class.md#createfont).  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView&#84;](../../mfc/codesnippet/cpp/cfontdialog-class_7.cpp)]  
  
##  <a name="isbold"></a>CFontDialog::IsBold  
 Chame essa função para determinar se a fonte selecionada está em negrito.  
  
```  
BOOL IsBold() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a fonte selecionada tem a característica em negrito ativada; Caso contrário, 0.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView&#85;](../../mfc/codesnippet/cpp/cfontdialog-class_8.cpp)]  
  
##  <a name="isitalic"></a>CFontDialog::IsItalic  
 Chame essa função para determinar se a fonte selecionada está em itálico.  
  
```  
BOOL IsItalic() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a fonte selecionada tem a característica itálico habilitada; Caso contrário, 0.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView&#86;](../../mfc/codesnippet/cpp/cfontdialog-class_9.cpp)]  
  
##  <a name="isstrikeout"></a>CFontDialog::IsStrikeOut  
 Chame essa função para determinar se a fonte selecionada é exibida com riscado.  
  
```  
BOOL IsStrikeOut() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a fonte selecionada tem a característica riscado habilitada; Caso contrário, 0.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView&#87;](../../mfc/codesnippet/cpp/cfontdialog-class_10.cpp)]  
  
##  <a name="isunderline"></a>CFontDialog::IsUnderline  
 Chame essa função para determinar se a fonte selecionada é sublinhada.  
  
```  
BOOL IsUnderline() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a fonte selecionada tem a característica de sublinhado ativada; Caso contrário, 0.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[88 NVC_MFCDocView](../../mfc/codesnippet/cpp/cfontdialog-class_11.cpp)]  
  
##  <a name="m_cf"></a>CFontDialog::m_cf  
 Uma estrutura cujos membros armazenam as características do objeto de caixa de diálogo.  
  
```  
CHOOSEFONT m_cf;  
```  
  
### <a name="remarks"></a>Comentários  
 Depois de criar um `CFontDialog` do objeto, você pode usar `m_cf` modificar vários aspectos da caixa de diálogo antes de chamar o `DoModal` função de membro. Para obter mais informações sobre essa estrutura, consulte [CHOOSEFONT](http://msdn.microsoft.com/library/windows/desktop/ms646832) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView&#89;](../../mfc/codesnippet/cpp/cfontdialog-class_12.cpp)]  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo MFC HIERSVR](../../visual-cpp-samples.md)   
 [Classe CCommonDialog](../../mfc/reference/ccommondialog-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)




