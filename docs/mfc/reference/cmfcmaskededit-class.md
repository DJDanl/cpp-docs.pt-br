---
title: Classe CMFCMaskedEdit | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CMFCMaskedEdit
- AFXMASKEDEDIT/CMFCMaskedEdit
- AFXMASKEDEDIT/CMFCMaskedEdit::DisableMask
- AFXMASKEDEDIT/CMFCMaskedEdit::EnableGetMaskedCharsOnly
- AFXMASKEDEDIT/CMFCMaskedEdit::EnableMask
- AFXMASKEDEDIT/CMFCMaskedEdit::EnableSelectByGroup
- AFXMASKEDEDIT/CMFCMaskedEdit::EnableSetMaskedCharsOnly
- AFXMASKEDEDIT/CMFCMaskedEdit::GetWindowText
- AFXMASKEDEDIT/CMFCMaskedEdit::SetValidChars
- AFXMASKEDEDIT/CMFCMaskedEdit::SetWindowText
- AFXMASKEDEDIT/CMFCMaskedEdit::IsMaskedChar
dev_langs: C++
helpviewer_keywords:
- CMFCMaskedEdit [MFC], DisableMask
- CMFCMaskedEdit [MFC], EnableGetMaskedCharsOnly
- CMFCMaskedEdit [MFC], EnableMask
- CMFCMaskedEdit [MFC], EnableSelectByGroup
- CMFCMaskedEdit [MFC], EnableSetMaskedCharsOnly
- CMFCMaskedEdit [MFC], GetWindowText
- CMFCMaskedEdit [MFC], SetValidChars
- CMFCMaskedEdit [MFC], SetWindowText
- CMFCMaskedEdit [MFC], IsMaskedChar
ms.assetid: 13b1a645-2d5d-4c37-8599-16d5003f23a5
caps.latest.revision: "30"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: b0ada987b3226d901c3bf01236c2a593c2e36f51
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="cmfcmaskededit-class"></a>Classe CMFCMaskedEdit
O `CMFCMaskedEdit` classe oferece suporte a um controle de edição mascarada, que valida em relação a uma máscara de entrada do usuário e exibe os resultados validados de acordo com um modelo.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CMFCMaskedEdit : public CEdit  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|`CMFCMaskedEdit::CMFCMaskedEdit`|Construtor padrão.|  
|`CMFCMaskedEdit::~CMFCMaskedEdit`|Destruidor.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCMaskedEdit::DisableMask](#disablemask)|Desabilita a validação de entrada do usuário.|  
|[CMFCMaskedEdit::EnableGetMaskedCharsOnly](#enablegetmaskedcharsonly)|Especifica se o `GetWindowText` método recupera somente os caracteres mascarados.|  
|[CMFCMaskedEdit::EnableMask](#enablemask)|Inicializa o mascarado de controle de edição.|  
|[CMFCMaskedEdit::EnableSelectByGroup](#enableselectbygroup)|Especifica se o controle de edição mascarada seleciona grupos específicos de entrada do usuário, ou todas as entrada do usuário.|  
|[CMFCMaskedEdit::EnableSetMaskedCharsOnly](#enablesetmaskedcharsonly)|Especifica se o texto é validado em relação somente mascarado caracteres, ou em relação a máscara inteira.|  
|`CMFCMaskedEdit::GetThisClass`|Usado pelo framework para obter um ponteiro para o [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) objeto associado esse tipo de classe.|  
|[CMFCMaskedEdit::GetWindowText](#getwindowtext)|Recupera validar texto do controle de edição mascarada.|  
|[CMFCMaskedEdit::SetValidChars](#setvalidchars)|Especifica uma cadeia de caracteres válidas que o usuário pode inserir.|  
|[CMFCMaskedEdit::SetWindowText](#setwindowtext)|Exibe um aviso no controle de edição mascarada.|  
  
### <a name="protected-methods"></a>Métodos Protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCMaskedEdit::IsMaskedChar](#ismaskedchar)|Chamado pelo framework para validar o caractere especificado com o caractere de máscara correspondente.|  
  
## <a name="remarks"></a>Comentários  
 Execute as seguintes etapas para usar o `CMFCMaskedEdit` controle em seu aplicativo:  
  
 1. Inserir uma `CMFCMaskedEdit` objeto em sua classe de janela.  
  
 2. Chamar o [CMFCMaskedEdit::EnableMask](#enablemask) método para especificar a máscara.  
  
 3. Chamar o [CMFCMaskedEdit::SetValidChars](#setvalidchars) método para especificar a lista de caracteres válidos.  
  
 4. Chamar o [CMFCMaskedEdit::SetWindowText](#setwindowtext) método para especificar o texto padrão para o controle de edição de máscara.  
  
 5. Chamar o [CMFCMaskedEdit::GetWindowText](#getwindowtext) método para recuperar o texto validado.  
  
 Se você não chama um ou mais métodos para inicializar a máscara, caracteres válidos e texto padrão, o controle de edição mascarada se comporta assim como o controle de edição padrão.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra como definir uma máscara (por exemplo, um número de telefone) usando o `EnableMask` método para criar a máscara para editar a máscara controle, o `SetValidChars` método para especificar uma cadeia de caracteres válidos que o usuário pode inserir e `SetWindowText` método para exibir um aviso no mascarado de controle de edição. Este exemplo é parte do [exemplo novos controles](../../visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_NewControls#11](../../mfc/reference/codesnippet/cpp/cmfcmaskededit-class_1.h)]  
[!code-cpp[NVC_MFC_NewControls#12](../../mfc/reference/codesnippet/cpp/cmfcmaskededit-class_2.cpp)]  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 [CEdit](../../mfc/reference/cedit-class.md)  
  
 [CMFCMaskedEdit](../../mfc/reference/cmfcmaskededit-class.md)  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxmaskededit.h  
  
##  <a name="disablemask"></a>CMFCMaskedEdit::DisableMask  
 Desabilita a validação de entrada do usuário.  
  
```  
void DisableMask();
```  
  
### <a name="remarks"></a>Comentários  
 Se a validação de entrada do usuário é desabilitada, o controle de edição mascarada se comporta como o padrão de controle de edição.  
  
##  <a name="enablegetmaskedcharsonly"></a>CMFCMaskedEdit::EnableGetMaskedCharsOnly  
 Especifica se o `GetWindowText` método recupera somente os caracteres mascarados.  
  
```  
void EnableGetMaskedCharsOnly(BOOL bEnable=TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bEnable`  
 `TRUE`para especificar que o [CMFCMaskedEdit::GetWindowText](#getwindowtext) método recuperar apenas mascarado caracteres; `FALSE` para especificar o método de recuperar o texto inteiro. O valor padrão é `TRUE`.  
  
### <a name="remarks"></a>Comentários  
 Use esse método para habilitar a recuperação caracteres mascarados. Em seguida, crie um controle de edição mascarada que corresponde ao número de telefone, como (425) 555-0187. Se você chamar o `GetWindowText` método, ele retorna "4255550187". Se você desabilitar a recuperação caracteres mascarados, o `GetWindowText` método retorna o texto que é exibido no controle de edição, por exemplo "(425) 555-0187".  
  
##  <a name="enablemask"></a>CMFCMaskedEdit::EnableMask  
 Inicializa o mascarado de controle de edição.  
  
```  
void EnableMask(
    LPCTSTR lpszMask,  
    LPCTSTR lpszInputTemplate,  
    TCHAR chMaskInputTemplate=_T('_'),  
    LPCTSTR lpszValid=NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `lpszMask`  
 Uma cadeia de caracteres de máscara que especifica o tipo de caractere que pode ser exibido em cada posição na entrada do usuário. O comprimento do `lpszInputTemplate` e `lpszMask` cadeias de caracteres do parâmetro devem ser o mesmo. Consulte a seção de comentários para obter mais detalhes sobre os caracteres de máscara.  
  
 [in] `lpszInputTemplate`  
 Uma cadeia de caracteres de modelo de máscara que especifica que o literal de caracteres que pode ser exibido em cada posição na entrada do usuário. Use o caractere de sublinhado ('_') como um espaço reservado de caractere. O comprimento do `lpszInputTemplate` e `lpszMask` cadeias de caracteres do parâmetro devem ser o mesmo.  
  
 [in] `chMaskInputTemplate`  
 Um caractere padrão que substitui a estrutura para cada caractere inválido na entrada do usuário. O valor padrão desse parâmetro é o caractere de sublinhado ('_').  
  
 [in] `lpszValid`  
 Uma cadeia de caracteres que contém um conjunto de caracteres válidos. `NULL`indica que todos os caracteres são válidos. O valor padrão desse parâmetro é `NULL`.  
  
### <a name="remarks"></a>Comentários  
 Use esse método para criar a máscara para o controle de edição mascarada. Derivar uma classe a partir de `CMFCMaskedEdit` classe e substituir o [CMFCMaskedEdit::IsMaskedChar](#ismaskedchar) método para usar seu próprio código para o processamento de máscara personalizada.  
  
 A tabela a seguir lista os caracteres de máscara padrão:  
  
|Caractere de máscara|Definição|  
|--------------------|----------------|  
|D|Dígito.|  
|d|Dígito ou espaço.|  
|+|Sinal de adição ('+ '), menos ('-'), ou espaço.|  
|C|Caractere alfabético.|  
|c|Caractere alfabético ou um espaço.|  
|Um|Caractere alfanumérico.|  
|a|Caractere alfanumérico ou espaço.|  
|*|Um caractere imprimível.|  
  
##  <a name="enableselectbygroup"></a>CMFCMaskedEdit::EnableSelectByGroup  
 Especifica se o controle de edição mascarado permite que o usuário selecione grupos de determinada entrada, ou todas as entradas.  
  
```  
void EnableSelectByGroup(BOOL bEnable=TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bEnable`  
 `TRUE`para selecionar apenas grupos; `FALSE` para selecionar o texto inteiro. O valor padrão é `TRUE`.  
  
### <a name="remarks"></a>Comentários  
 Use esta função para especificar se o controle de edição mascarado permite que um usuário selecione por grupo ou o texto inteiro.  
  
 Por padrão, a seleção de grupo está habilitada. Nesse caso, o usuário pode selecionar apenas grupos contínuos de caracteres válidos.  
  
 Por exemplo, você pode usar o controle de edição mascarada a seguir para validar um número de telefone:  
  
 `m_wndMaskEdit.EnableMask(`  
  
 `_T(" ddd  ddd dddd"),// Mask string`  
  
 `_T("(___) ___-____"),// Template string`  
  
 `_T(' '));// Default char`  
  
 `m_wndMaskEdit.SetValidChars(NULL); // All characters are valid.`  
  
 `m_wndMaskEdit.SetWindowText(_T("(425) 555-0187")); // Prompt`  
  
 Se a seleção por grupo é ativada, o usuário pode recuperar apenas o "425", "555" ou "0187" grupos de cadeia de caracteres. Se a seleção de grupo estiver desabilitada o usuário pode recuperar o texto inteiro do número de telefone: "(425) 555-0187".  
  
##  <a name="enablesetmaskedcharsonly"></a>CMFCMaskedEdit::EnableSetMaskedCharsOnly  
 Especifica se o texto é validado em relação a somente os caracteres mascarados ou em relação a máscara inteira.  
  
```  
void EnableSetMaskedCharsOnly(BOOL bEnable=TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bEnable`  
 `TRUE`para validar o usuário entrada com relação ao mascarado somente caracteres; `FALSE` para validar em relação a máscara inteira. O valor padrão é `TRUE`.  
  
##  <a name="getwindowtext"></a>CMFCMaskedEdit::GetWindowText  
 Recupera validar texto do controle de edição mascarada.  
  
```  
int GetWindowText(
    LPTSTR lpszStringBuf,  
    int nMaxCount) const;  
  
void GetWindowText(CString& rstrString) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [out] `lpszStringBuf`  
 Um ponteiro para um buffer que recebe o texto do controle de edição.  
  
 [in] `nMaxCount`  
 O número máximo de caracteres a ser exibida.  
  
 [out] `rstrString`  
 Uma referência para o objeto de cadeia de caracteres que recebe o texto do controle de edição.  
  
### <a name="return-value"></a>Valor de retorno  
 A primeira sobrecarga de método retorna o número de bytes da cadeia de caracteres que é copiado para o `lpszStringBuf` o buffer de parâmetros; 0 se o controle de edição mascarada não tiver texto.  
  
### <a name="remarks"></a>Comentários  
 Esse método copia o texto do controle de edição mascarada para o `lpszStringBuf` buffer ou `rstrString` cadeia de caracteres.  
  
 Este método redefine [CWnd::GetWindowText](../../mfc/reference/cwnd-class.md#getwindowtext).  
  
##  <a name="ismaskedchar"></a>CMFCMaskedEdit::IsMaskedChar  
 Chamado pelo framework para validar o caractere especificado com o caractere de máscara correspondente.  
  
```  
virtual BOOL IsMaskedChar(
    TCHAR chChar,  
    TCHAR chMaskChar) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `chChar`  
 O caractere a ser validado.  
  
 [in] `chMaskChar`  
 O caractere correspondente de cadeia de caracteres de máscara.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se o `chChar` parâmetro é o tipo de caractere permitido pelo `chMaskChar` parâmetro; caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Substitua este método para validar os caracteres de entrada por conta própria. Para obter mais informações sobre caracteres de máscara, consulte o [CMFCMaskedEdit::EnableMask](#enablemask) método.  
  
##  <a name="setvalidchars"></a>CMFCMaskedEdit::SetValidChars  
 Especifica uma cadeia de caracteres válidas que o usuário pode inserir.  
  
```  
void SetValidChars(LPCTSTR lpszValid=NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `lpszValid`  
 Uma cadeia de caracteres que contém o conjunto de caracteres de entrada válidos. `NULL`significa que todos os caracteres são válidos. O valor padrão desse parâmetro é `NULL`.  
  
### <a name="remarks"></a>Comentários  
 Use esse método para definir uma lista de caracteres válidos. Se um caractere de entrada não está na lista, o controle de edição mascarada não o aceita.  
  
 O exemplo de código a seguir aceita apenas números hexadecimais.  
  
 `//Mask: 0xFFFFm_wndMaskEdit.EnableMask( _T(" AAAA"),                // The mask string. _T("0x____"),               // The literal template string. _T('_'));                   // The default character that replaces the backspace character.// Valid string charactersm_wndMaskEdit.SetValidChars(_T("1234567890ABCDEFabcdef"));m_wndMaskEdit.SetWindowText(_T("0x01AF"));`  
  
##  <a name="setwindowtext"></a>CMFCMaskedEdit::SetWindowText  
 Exibe um aviso no controle de edição mascarada.  
  
```  
void SetWindowText(LPCTSTR lpszString);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `lpszString`  
 Aponta para uma cadeia de caracteres terminada em nulo que será usado como um prompt.  
  
### <a name="remarks"></a>Comentários  
 Esse método define o texto do controle.  
  
 Este método redefine [CWnd::SetWindowText](../../mfc/reference/cwnd-class.md#setwindowtext).  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)   
 [Classe CEdit](../../mfc/reference/cedit-class.md)
