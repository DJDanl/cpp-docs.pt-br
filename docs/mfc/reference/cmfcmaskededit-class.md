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
ms.openlocfilehash: de28b308ec235e33e39aabd707677f4e75320b0b
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81365288"
---
# <a name="cmfcmaskededit-class"></a>Classe CMFCMaskedEdit

A `CMFCMaskedEdit` classe suporta um controle de edição mascarado, que valida a entrada do usuário contra uma máscara e exibe os resultados validados de acordo com um modelo.

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
|[CMFCMaskedEdit::DisableMask](#disablemask)|Desabilita a validação da entrada do usuário.|
|[CMFCMaskedEdit::EnableGetMaskedCharsOnly](#enablegetmaskedcharsonly)|Especifica se `GetWindowText` o método recupera apenas caracteres mascarados.|
|[CMFCMaskedEdit::AtivarMáscara](#enablemask)|Inicializa o controle de edição mascarado.|
|[CMFCMaskedEdit::HabilitarSelectByGroup](#enableselectbygroup)|Especifica se o controle de edição mascarado seleciona grupos específicos de entrada do usuário ou todas as entradas do usuário.|
|[CMFCMaskedEdit::EnableSetMaskedCharsOnly](#enablesetmaskedcharsonly)|Especifica se o texto é validado apenas contra caracteres mascarados ou contra toda a máscara.|
|`CMFCMaskedEdit::GetThisClass`|Usado pela estrutura para obter um ponteiro para o objeto [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) que está associado a este tipo de classe.|
|[CMFCMaskedEdit::GetWindowText](#getwindowtext)|Recupera texto validado do controle de edição mascarado.|
|[CMFCMaskedEdit::SetValidChars](#setvalidchars)|Especifica uma seqüência de caracteres válidos que o usuário pode inserir.|
|[CMFCMaskedEdit::SetWindowText](#setwindowtext)|Exibe um prompt no controle de edição mascarado.|

### <a name="protected-methods"></a>Métodos Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CMFCMaskedEdit::IsMascaradoChar](#ismaskedchar)|Chamado pelo framework para validar o caractere especificado em relação ao caractere da máscara correspondente.|

## <a name="remarks"></a>Comentários

Execute as seguintes `CMFCMaskedEdit` etapas para usar o controle em seu aplicativo:

1. Incorpore `CMFCMaskedEdit` um objeto na sua classe de janela.

2. Ligue para o [método CMFCMaskedEdit::EnableMask](#enablemask) para especificar a máscara.

3. Ligue para o [método CMFCMaskedEdit::SetValidChars](#setvalidchars) para especificar a lista de caracteres válidos.

4. Ligue para o [método CMFCMaskedEdit::SetWindowText](#setwindowtext) para especificar o texto padrão para o controle de edição mascarado.

5. Ligue para o [método CMFCMaskedEdit::GetWindowText](#getwindowtext) para recuperar o texto validado.

Se você não chamar um ou mais métodos para inicializar a máscara, caracteres válidos e texto padrão, o controle de edição mascarado se comporta assim como o controle de edição padrão se comporta.

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra como configurar uma máscara (por `EnableMask` exemplo, um número de telefone) `SetValidChars` usando o método para criar a máscara para `SetWindowText` o controle de edição mascarado, o método para especificar uma seqüência de caracteres válidos que o usuário pode inserir e o método para exibir um prompt no controle de edição mascarado. Este exemplo faz parte da [amostra Novos Controles](../../overview/visual-cpp-samples.md).

[!code-cpp[NVC_MFC_NewControls#11](../../mfc/reference/codesnippet/cpp/cmfcmaskededit-class_1.h)]
[!code-cpp[NVC_MFC_NewControls#12](../../mfc/reference/codesnippet/cpp/cmfcmaskededit-class_2.cpp)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CEdit](../../mfc/reference/cedit-class.md)

[Cmfcmaskededit](../../mfc/reference/cmfcmaskededit-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxmaskededit.h

## <a name="cmfcmaskededitdisablemask"></a><a name="disablemask"></a>CMFCMaskedEdit::DisableMask

Desabilita a validação da entrada do usuário.

```
void DisableMask();
```

### <a name="remarks"></a>Comentários

Se a validação de entrada do usuário estiver desativada, o controle de edição mascarado se comportará como o controle de edição padrão.

## <a name="cmfcmaskededitenablegetmaskedcharsonly"></a><a name="enablegetmaskedcharsonly"></a>CMFCMaskedEdit::EnableGetMaskedCharsOnly

Especifica se `GetWindowText` o método recupera apenas caracteres mascarados.

```
void EnableGetMaskedCharsOnly(BOOL bEnable=TRUE);
```

### <a name="parameters"></a>Parâmetros

*Benable*<br/>
[em] TRUE para especificar que o [método CMFCMaskedEdit::GetWindowText](#getwindowtext) recuperar apenas caracteres mascarados; FALSO para especificar que o método recuperar á mensagem inteira. O valor padrão é TRUE.

### <a name="remarks"></a>Comentários

Use este método para permitir a recuperação de caracteres mascarados. Em seguida, crie um controle de edição mascarado que corresponda ao número de telefone, como (425) 555-0187. Se você `GetWindowText` chamar o método, ele retorna "4255550187". Se você desativar a recuperação de `GetWindowText` caracteres mascarados, o método reapossoo o texto exibido no controle de edição, por exemplo "(425) 555-0187".

## <a name="cmfcmaskededitenablemask"></a><a name="enablemask"></a>CMFCMaskedEdit::AtivarMáscara

Inicializa o controle de edição mascarado.

```
void EnableMask(
    LPCTSTR lpszMask,
    LPCTSTR lpszInputTemplate,
    TCHAR chMaskInputTemplate=_T('_'),
    LPCTSTR lpszValid=NULL);
```

### <a name="parameters"></a>Parâmetros

*lpszMask*<br/>
[em] Uma seqüência de máscaraque especifica o tipo de caractere que pode aparecer em cada posição na entrada do usuário. O comprimento das seqüências de *parâmetros lpszInputTemplate* e *lpszMask* deve ser o mesmo. Consulte a seção Observações para obter mais detalhes sobre os caracteres da máscara.

*lpszInputTemplate*<br/>
[em] Uma seqüência de modelo de máscara que especifica os caracteres literais que podem aparecer em cada posição na entrada do usuário. Use o caractere sublinhado ('_') como um espaço reservado de caracteres. O comprimento das seqüências de *parâmetros lpszInputTemplate* e *lpszMask* deve ser o mesmo.

*chMaskInputTemplate*<br/>
[em] Um caractere padrão que a estrutura substitui para cada caractere inválido na entrada do usuário. O valor padrão deste parâmetro é sublinhado ('_').

*lpszValid*<br/>
[em] Uma seqüência que contém um conjunto de caracteres válidos. NULL indica que todos os caracteres são válidos. O valor padrão deste parâmetro é NULL.

### <a name="remarks"></a>Comentários

Use este método para criar a máscara para o controle de edição mascarado. Obtenha uma classe `CMFCMaskedEdit` da classe e anule o método [CMFCMaskedEdit::IsMaskedChar](#ismaskedchar) para usar seu próprio código para processamento personalizado de máscaras.

A tabela a seguir lista os caracteres de máscara padrão:

|Personagem da máscara|Definição|
|--------------------|----------------|
|D|Dígito.|
|d|Dígito ou espaço.|
|+|Mais ('+'), menos ('-'), ou espaço.|
|C|Caráter alfabético.|
|c|Caráter alfabético ou espaço.|
|Um|Caráter alfanumérico.|
|a|Caráter alfanumérico ou espaço.|
|*|Um personagem imprimível.|

## <a name="cmfcmaskededitenableselectbygroup"></a><a name="enableselectbygroup"></a>CMFCMaskedEdit::HabilitarSelectByGroup

Especifica se o controle de edição mascarado permite que o usuário selecione determinada entrada de grupos ou todas as entradas.

```
void EnableSelectByGroup(BOOL bEnable=TRUE);
```

### <a name="parameters"></a>Parâmetros

*Benable*<br/>
[em] VERDADEIRO para selecionar apenas grupos; FALSO para selecionar o texto inteiro. O valor padrão é TRUE.

### <a name="remarks"></a>Comentários

Use esta função para especificar se o controle de edição mascarado permite que um usuário selecione por grupo ou por todo o texto.

Por padrão, a seleção por grupo está ativada. Neste caso, o usuário pode selecionar apenas grupos contínuos de caracteres válidos.

Por exemplo, você pode usar o seguinte controle de edição mascarado para validar um número de telefone:

```cpp
m_wndMaskEdit.EnableMask(
    _T(" ddd  ddd dddd"),  // Mask string
    _T("(___) ___-____"),  // Template string
    _T(' '));              // Default char

m_wndMaskEdit.SetValidChars(NULL); // All characters are valid.

m_wndMaskEdit.SetWindowText(_T("(425) 555-0187")); // Prompt
```

Se a seleção por grupo estiver ativada, o usuário poderá recuperar apenas os grupos de strings "425", "555" ou "0187". Se a seleção do grupo for desativada, o usuário poderá recuperar todo o texto do número de telefone: "(425) 555-0187".

## <a name="cmfcmaskededitenablesetmaskedcharsonly"></a><a name="enablesetmaskedcharsonly"></a>CMFCMaskedEdit::EnableSetMaskedCharsOnly

Especifica se o texto é validado apenas contra os caracteres mascarados ou contra toda a máscara.

```
void EnableSetMaskedCharsOnly(BOOL bEnable=TRUE);
```

### <a name="parameters"></a>Parâmetros

*Benable*<br/>
[em] TRUE para validar a entrada do usuário contra apenas caracteres mascarados; FALSO para validar contra toda a máscara. O valor padrão é TRUE.

## <a name="cmfcmaskededitgetwindowtext"></a><a name="getwindowtext"></a>CMFCMaskedEdit::GetWindowText

Recupera texto validado do controle de edição mascarado.

```
int GetWindowText(
    LPTSTR lpszStringBuf,
    int nMaxCount) const;

void GetWindowText(CString& rstrString) const;
```

### <a name="parameters"></a>Parâmetros

*lpszStringBuf*<br/>
[fora] Um ponteiro para um buffer que recebe o texto do controle de edição.

*Nmaxcount*<br/>
[em] O número máximo de caracteres a receber.

*rstrString*<br/>
[fora] Uma referência ao objeto de seqüência que recebe o texto do controle de edição.

### <a name="return-value"></a>Valor retornado

A primeira sobrecarga do método retorna o número de bytes da string copiado para o buffer de *parâmetros lpszStringBuf;* 0 se o controle de edição mascarado não tiver texto.

### <a name="remarks"></a>Comentários

Este método copia o texto do controle de edição mascarado para o buffer *lpszStringBuf* ou a seqüência *rstrString.*

Este método redefine [CWnd::GetWindowText](../../mfc/reference/cwnd-class.md#getwindowtext).

## <a name="cmfcmaskededitismaskedchar"></a><a name="ismaskedchar"></a>CMFCMaskedEdit::IsMascaradoChar

Chamado pelo framework para validar o caractere especificado em relação ao caractere da máscara correspondente.

```
virtual BOOL IsMaskedChar(
    TCHAR chChar,
    TCHAR chMaskChar) const;
```

### <a name="parameters"></a>Parâmetros

*chChar*<br/>
[em] O caráter a ser validado.

*chMaskChar*<br/>
[em] O caractere correspondente da seqüência da máscara.

### <a name="return-value"></a>Valor retornado

VERDADE se o parâmetro *chChar* for o tipo de caractere permitido pelo parâmetro *chMaskChar;* caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Anular este método para validar caracteres de entrada por conta própria. Para obter mais informações sobre caracteres de máscara, consulte o método [CMFCMaskedEdit::EnableMask.](#enablemask)

## <a name="cmfcmaskededitsetvalidchars"></a><a name="setvalidchars"></a>CMFCMaskedEdit::SetValidChars

Especifica uma seqüência de caracteres válidos que o usuário pode inserir.

```
void SetValidChars(LPCTSTR lpszValid=NULL);
```

### <a name="parameters"></a>Parâmetros

*lpszValid*<br/>
[em] Uma seqüência que contém o conjunto de caracteres de entrada válidos. NULL significa que todos os caracteres são válidos. O valor padrão deste parâmetro é NULL.

### <a name="remarks"></a>Comentários

Use este método para definir uma lista de caracteres válidos. Se um caractere de entrada não estiver nesta lista, o controle de edição mascarado não o aceitará.

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

## <a name="cmfcmaskededitsetwindowtext"></a><a name="setwindowtext"></a>CMFCMaskedEdit::SetWindowText

Exibe um prompt no controle de edição mascarado.

```
void SetWindowText(LPCTSTR lpszString);
```

### <a name="parameters"></a>Parâmetros

*lpszString*<br/>
[em] Aponta para uma seqüência de terminadas nula que será usada como um prompt.

### <a name="remarks"></a>Comentários

Este método define o texto de controle.

Este método redefine [CWnd::SetWindowText](../../mfc/reference/cwnd-class.md#setwindowtext).

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CEdit](../../mfc/reference/cedit-class.md)
