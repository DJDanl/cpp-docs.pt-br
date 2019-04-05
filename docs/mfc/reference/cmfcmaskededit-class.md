---
title: Classe CMFCMaskedEdit
ms.date: 11/04/2016
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
ms.openlocfilehash: c1dcf89811fa5225283cb5bec120d3bd2fdfb003
ms.sourcegitcommit: c7f90df497e6261764893f9cc04b5d1f1bf0b64b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/05/2019
ms.locfileid: "58773782"
---
# <a name="cmfcmaskededit-class"></a>Classe CMFCMaskedEdit

O `CMFCMaskedEdit` classe dá suporte a um controle de edição mascarado, que valida a entrada do usuário em relação a uma máscara e exibe os resultados validados de acordo com um modelo.

## <a name="syntax"></a>Sintaxe

```
class CMFCMaskedEdit : public CEdit
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|`CMFCMaskedEdit::CMFCMaskedEdit`|Construtor padrão.|
|`CMFCMaskedEdit::~CMFCMaskedEdit`|Destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCMaskedEdit::DisableMask](#disablemask)|Desabilita a validação de entrada do usuário.|
|[CMFCMaskedEdit::EnableGetMaskedCharsOnly](#enablegetmaskedcharsonly)|Especifica se o `GetWindowText` método recupera somente os caracteres mascarados.|
|[CMFCMaskedEdit::EnableMask](#enablemask)|Inicializa o mascarada controle de edição.|
|[CMFCMaskedEdit::EnableSelectByGroup](#enableselectbygroup)|Especifica se o controle de edição mascarado seleciona grupos específicos de entrada do usuário, ou todas as entrada do usuário.|
|[CMFCMaskedEdit::EnableSetMaskedCharsOnly](#enablesetmaskedcharsonly)|Especifica se o texto é validado em relação apenas mascarado caracteres, ou em relação a máscara inteira.|
|`CMFCMaskedEdit::GetThisClass`|Usado pelo framework para obter um ponteiro para o [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) objeto que está associado com esse tipo de classe.|
|[CMFCMaskedEdit::GetWindowText](#getwindowtext)|Recupera validado o texto do controle de edição mascarado.|
|[CMFCMaskedEdit::SetValidChars](#setvalidchars)|Especifica uma cadeia de caracteres válidas que o usuário pode inserir.|
|[CMFCMaskedEdit::SetWindowText](#setwindowtext)|Exibe um prompt no controle de edição mascarado.|

### <a name="protected-methods"></a>Métodos Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CMFCMaskedEdit::IsMaskedChar](#ismaskedchar)|Chamado pelo framework para validar o caractere especificado em relação ao caractere de máscara correspondente.|

## <a name="remarks"></a>Comentários

Execute as seguintes etapas para usar o `CMFCMaskedEdit` controle em seu aplicativo:

1. Incorporar um `CMFCMaskedEdit` objeto em sua classe de janela.

2. Chame o [CMFCMaskedEdit::EnableMask](#enablemask) método para especificar a máscara.

3. Chame o [CMFCMaskedEdit::SetValidChars](#setvalidchars) método para especificar a lista de caracteres válidas.

4. Chame o [CMFCMaskedEdit::SetWindowText](#setwindowtext) método para especificar o texto padrão para o controle de edição a mascarado.

5. Chame o [CMFCMaskedEdit::GetWindowText](#getwindowtext) método para recuperar o texto validado.

Se você não chamar métodos de um ou mais para inicializar a máscara, o caracteres válidos e o texto padrão, o controle de edição mascarado se comporta exatamente como o controle de edição padrão se comporta.

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra como definir uma máscara (por exemplo, um número de telefone) usando o `EnableMask` método para criar a máscara para a máscara de controle, edite o `SetValidChars` método para especificar uma cadeia de caracteres válidos que o usuário pode inserir e `SetWindowText` controle de edição do método para exibir um aviso no mascarado. Este exemplo é parte do [exemplo de novos controles](../../overview/visual-cpp-samples.md).

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

##  <a name="disablemask"></a>  CMFCMaskedEdit::DisableMask

Desabilita a validação de entrada do usuário.

```
void DisableMask();
```

### <a name="remarks"></a>Comentários

Se a validação de entrada do usuário é desabilitada, o controle de edição mascarado se comporta como o padrão de controle de edição.

##  <a name="enablegetmaskedcharsonly"></a>  CMFCMaskedEdit::EnableGetMaskedCharsOnly

Especifica se o `GetWindowText` método recupera somente os caracteres mascarados.

```
void EnableGetMaskedCharsOnly(BOOL bEnable=TRUE);
```

### <a name="parameters"></a>Parâmetros

*bAtivar*<br/>
[in] TRUE para especificar que o [CMFCMaskedEdit::GetWindowText](#getwindowtext) método retrieve apenas mascarado caracteres; FALSO para especificar que o método de recuperar o texto inteiro. O valor padrão é TRUE.

### <a name="remarks"></a>Comentários

Use esse método para habilitar a recuperar caracteres mascarados. Em seguida, crie um controle de edição mascarado que corresponde ao número de telefone, como (425) 555-0187. Se você chamar o `GetWindowText` método, ele retorna "4255550187". Se você desabilitar a recuperar caracteres mascarados, o `GetWindowText` método retorna o texto que é exibido no controle de edição, por exemplo "(425) 555-0187".

##  <a name="enablemask"></a>  CMFCMaskedEdit::EnableMask

Inicializa o mascarada controle de edição.

```
void EnableMask(
    LPCTSTR lpszMask,
    LPCTSTR lpszInputTemplate,
    TCHAR chMaskInputTemplate=_T('_'),
    LPCTSTR lpszValid=NULL);
```

### <a name="parameters"></a>Parâmetros

*lpszMask*<br/>
[in] Uma cadeia de caracteres de máscara que especifica o tipo de caractere que pode ser exibido em cada posição na entrada do usuário. O comprimento do *lpszInputTemplate* e *lpszMask* cadeias de caracteres do parâmetro devem ser o mesmo. Consulte a seção de comentários para obter mais detalhes sobre os caracteres de máscara.

*lpszInputTemplate*<br/>
[in] Uma cadeia de caracteres de modelo de máscara que especifica que o literal de caracteres que pode ser exibido em cada posição na entrada do usuário. Use o caractere de sublinhado ('_') como um espaço reservado de caractere. O comprimento do *lpszInputTemplate* e *lpszMask* cadeias de caracteres do parâmetro devem ser o mesmo.

*chMaskInputTemplate*<br/>
[in] Um caractere de padrão que o framework substitui cada caractere inválido na entrada do usuário. O valor padrão desse parâmetro é o caractere de sublinhado ('_').

*lpszValid*<br/>
[in] Uma cadeia de caracteres que contém um conjunto de caracteres válidos. NULL indica que todos os caracteres são válidos. O valor padrão desse parâmetro é NULL.

### <a name="remarks"></a>Comentários

Use esse método para criar a máscara para o controle de edição mascarado. Derive uma classe do `CMFCMaskedEdit` de classe e substituir o [CMFCMaskedEdit::IsMaskedChar](#ismaskedchar) método para usar seu próprio código para o processamento da máscara personalizada.

A tabela a seguir lista os caracteres de máscara de padrão:

|Caractere de máscara|Definição|
|--------------------|----------------|
|D|Dígito.|
|d|Dígito ou espaço.|
|+|Sinal de adição ('+ '), menos ('-'), ou espaço.|
|C|Caractere alfabético.|
|c|Caractere alfabético ou espaço.|
|Um|Caractere alfanumérico.|
|a|Caractere alfanumérico ou espaço.|
|*|Um caractere imprimível.|

##  <a name="enableselectbygroup"></a>  CMFCMaskedEdit::EnableSelectByGroup

Especifica se o controle de edição mascarado permite que o usuário selecione grupos específicos de entrada ou toda a entrada.

```
void EnableSelectByGroup(BOOL bEnable=TRUE);
```

### <a name="parameters"></a>Parâmetros

*bAtivar*<br/>
[in] TRUE para selecionar apenas grupos; FALSE para selecionar o texto inteiro. O valor padrão é TRUE.

### <a name="remarks"></a>Comentários

Use essa função para especificar se o controle de edição mascarado permite ao usuário selecionar por grupo ou o texto inteiro.

Por padrão, a seleção de grupo está habilitada. Nesse caso, o usuário pode selecionar apenas grupos contínuos de caracteres válidos.

Por exemplo, você pode usar o controle de edição mascarado a seguir para validar um número de telefone:

```cpp
m_wndMaskEdit.EnableMask(
    _T(" ddd  ddd dddd"),  // Mask string
    _T("(___) ___-____"),  // Template string
    _T(' '));              // Default char

m_wndMaskEdit.SetValidChars(NULL); // All characters are valid.

m_wndMaskEdit.SetWindowText(_T("(425) 555-0187")); // Prompt
```

Se a seleção por grupo está habilitada, o usuário pode recuperar apenas o "425", "555" ou "0187" grupos de cadeia de caracteres. Se a seleção de grupo estiver desabilitada o usuário pode recuperar o texto inteiro do número de telefone: "(425) 555-0187".

##  <a name="enablesetmaskedcharsonly"></a>  CMFCMaskedEdit::EnableSetMaskedCharsOnly

Especifica se o texto é validado em relação a somente os caracteres mascarados ou contra a máscara inteira.

```
void EnableSetMaskedCharsOnly(BOOL bEnable=TRUE);
```

### <a name="parameters"></a>Parâmetros

*bAtivar*<br/>
[in] TRUE para validar a entrada em relação a apenas mascarado caracteres; do usuário FALSE para validar contra a máscara inteira. O valor padrão é TRUE.

##  <a name="getwindowtext"></a>  CMFCMaskedEdit::GetWindowText

Recupera validado o texto do controle de edição mascarado.

```
int GetWindowText(
    LPTSTR lpszStringBuf,
    int nMaxCount) const;

void GetWindowText(CString& rstrString) const;
```

### <a name="parameters"></a>Parâmetros

*lpszStringBuf*<br/>
[out] Um ponteiro para um buffer que recebe o texto do controle de edição.

*nMaxCount*<br/>
[in] O número máximo de caracteres a receber.

*rstrString*<br/>
[out] Uma referência ao objeto de cadeia de caracteres que recebe o texto do controle de edição.

### <a name="return-value"></a>Valor de retorno

A primeira sobrecarga de método retorna o número de bytes da cadeia de caracteres que é copiado para o *lpszStringBuf* buffers de parâmetro; 0 se o controle de edição mascarado não possui um texto.

### <a name="remarks"></a>Comentários

Esse método copia o texto do controle de edição mascarado para o *lpszStringBuf* buffer ou o *rstrString* cadeia de caracteres.

Este método redefine [CWnd::GetWindowText](../../mfc/reference/cwnd-class.md#getwindowtext).

##  <a name="ismaskedchar"></a>  CMFCMaskedEdit::IsMaskedChar

Chamado pelo framework para validar o caractere especificado em relação ao caractere de máscara correspondente.

```
virtual BOOL IsMaskedChar(
    TCHAR chChar,
    TCHAR chMaskChar) const;
```

### <a name="parameters"></a>Parâmetros

*chChar*<br/>
[in] O caractere a ser validado.

*chMaskChar*<br/>
[in] O caractere correspondente da cadeia de caracteres de máscara.

### <a name="return-value"></a>Valor de retorno

TRUE se o *chChar* parâmetro é o tipo de caractere permitido pela *chMaskChar* parâmetro; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Substitua este método para validar os caracteres de entrada por conta própria. Para obter mais informações sobre caracteres de máscara, consulte o [CMFCMaskedEdit::EnableMask](#enablemask) método.

##  <a name="setvalidchars"></a>  CMFCMaskedEdit::SetValidChars

Especifica uma cadeia de caracteres válidas que o usuário pode inserir.

```
void SetValidChars(LPCTSTR lpszValid=NULL);
```

### <a name="parameters"></a>Parâmetros

*lpszValid*<br/>
[in] Uma cadeia de caracteres que contém o conjunto de caracteres de entrada válidos. NULL significa que todos os caracteres são válidos. O valor padrão desse parâmetro é NULL.

### <a name="remarks"></a>Comentários

Use esse método para definir uma lista de caracteres válidas. Se um caractere de entrada não estiver nessa lista, o controle de edição mascarado não aceitá-lo.

O exemplo de código a seguir aceita apenas números hexadecimais.

```cpp
//Mask: 0xFFFF
m_wndMaskEdit.EnableMask(
    _T(" AAAA"),                // The mask string.
    _T("0x____"),               // The literal template string.
    _T('_'));                   // The default character that
                                // replaces the backspace character.
// Valid string characters
m_wndMaskEdit.SetValidChars(_T("1234567890ABCDEFabcdef"));m_wndMaskEdit.SetWindowText(_T("0x01AF"));
```

##  <a name="setwindowtext"></a>  CMFCMaskedEdit::SetWindowText

Exibe um prompt no controle de edição mascarado.

```
void SetWindowText(LPCTSTR lpszString);
```

### <a name="parameters"></a>Parâmetros

*lpszString*<br/>
[in] Aponta para uma cadeia de caracteres terminada em nulo que será usado como um prompt.

### <a name="remarks"></a>Comentários

Esse método define o texto do controle.

Este método redefine [CWnd::SetWindowText](../../mfc/reference/cwnd-class.md#setwindowtext).

## <a name="see-also"></a>Consulte também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CEdit](../../mfc/reference/cedit-class.md)
