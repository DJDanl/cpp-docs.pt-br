---
title: Classe CFontDialog
ms.date: 11/04/2016
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
helpviewer_keywords:
- CFontDialog [MFC], CFontDialog
- CFontDialog [MFC], DoModal
- CFontDialog [MFC], GetCharFormat
- CFontDialog [MFC], GetColor
- CFontDialog [MFC], GetCurrentFont
- CFontDialog [MFC], GetFaceName
- CFontDialog [MFC], GetSize
- CFontDialog [MFC], GetStyleName
- CFontDialog [MFC], GetWeight
- CFontDialog [MFC], IsBold
- CFontDialog [MFC], IsItalic
- CFontDialog [MFC], IsStrikeOut
- CFontDialog [MFC], IsUnderline
- CFontDialog [MFC], m_cf
ms.assetid: 6228d500-ed0f-4156-81e5-ab0d57d1dcf4
ms.openlocfilehash: 6a8e24b68f377235c1f1e21fbcd5618aebbe299a
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81755018"
---
# <a name="cfontdialog-class"></a>Classe CFontDialog

Permite incorporar uma caixa de diálogo de seleção de fontes em seu aplicativo.

## <a name="syntax"></a>Sintaxe

```
class CFontDialog : public CCommonDialog
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[cfontdialog::cfontdialog](#cfontdialog)|Constrói um objeto `CFontDialog`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CFontDialog::DoModal](#domodal)|Exibe a caixa de diálogo e permite que o usuário faça uma seleção.|
|[cfontdialog::getCharformat](#getcharformat)|Recupera a formatação de caracteres da fonte selecionada.|
|[cfontdialog::getColor](#getcolor)|Retorna a cor da fonte selecionada.|
|[cfontdialog::getCurrentfont](#getcurrentfont)|Atribui as características da fonte selecionada `LOGFONT` atualmente a uma estrutura.|
|[cfontdialog::getFacename](#getfacename)|Retorna o nome da face da fonte selecionada.|
|[cfontdialog::getSize](#getsize)|Retorna o tamanho do ponto da fonte selecionada.|
|[cfontdialog::getStyleName](#getstylename)|Retorna o nome de estilo da fonte selecionada.|
|[cfontdialog::getweight](#getweight)|Retorna o peso da fonte selecionada.|
|[cfontdialog::isbold](#isbold)|Determina se a fonte é em negrito.|
|[cfontdialog::isitalic](#isitalic)|Determina se a fonte é itálica.|
|[cfontdialog::isstrikeout](#isstrikeout)|Determina se a fonte é exibida com strikeout.|
|[cfontdialog::isUnderline](#isunderline)|Determina se a fonte está sublinhada.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[cFontDialog::m_cf](#m_cf)|Uma estrutura usada `CFontDialog` para personalizar um objeto.|

## <a name="remarks"></a>Comentários

Um `CFontDialog` objeto é uma caixa de diálogo com uma lista de fontes que estão atualmente instaladas no sistema. O usuário pode selecionar uma fonte específica da lista e, em seguida, essa seleção é relatada de volta ao aplicativo.

Para construir `CFontDialog` um objeto, use o construtor fornecido ou obtenha uma nova subclasse e use seu próprio construtor personalizado.

Uma `CFontDialog` vez que um objeto tenha `m_cf` sido construído, você pode usar a estrutura para inicializar os valores ou estados de controles na caixa de diálogo. A estrutura [m_cf](#m_cf) é do tipo [CHOOSEFONT](/windows/win32/api/commdlg/ns-commdlg-choosefontw). Para obter mais informações sobre esta estrutura, consulte o Windows SDK.

Depois de inicializar os controles do `DoModal` objeto de diálogo, ligue para a função membro para exibir a caixa de diálogo e permita que o usuário selecione uma fonte. `DoModal`retorna se o usuário selecionou o botão OK (IDOK) ou Cancelar (IDCANCEL).

Se `DoModal` retornar o IDOK, `CFontDialog`você pode usar uma das funções de membro para recuperar a entrada de informações pelo usuário.

Você pode usar a função Windows [CommDlgExtendedError](/windows/win32/api/commdlg/nf-commdlg-commdlgextendederror) para determinar se ocorreu um erro durante a inicialização da caixa de diálogo e para saber mais sobre o erro. Para obter mais informações sobre esta função, consulte o SDK do Windows.

`CFontDialog`conta com o COMMDLG. Arquivo DLL que é fornecido com as versões 3.1 do Windows e posteriores.

Para personalizar a caixa de `CFontDialog`diálogo, obtenha uma classe, forneça um modelo de diálogo personalizado e adicione um mapa de mensagem para processar as mensagens de notificação dos controles estendidos. Quaisquer mensagens não processadas devem ser passadas para a classe base.

Personalizar a função do gancho não é necessário.

Para obter mais `CFontDialog`informações sobre como usar, consulte [Classes de Diálogo Comuns](../../mfc/common-dialog-classes.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[Cdialog](../../mfc/reference/cdialog-class.md)

[Ccommondialog](../../mfc/reference/ccommondialog-class.md)

`CFontDialog`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdlgs.h

## <a name="cfontdialogcfontdialog"></a><a name="cfontdialog"></a>cfontdialog::cfontdialog

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

*plfInicial*<br/>
Um ponteiro para uma estrutura de dados [LOGFONT](/windows/win32/api/wingdi/ns-wingdi-logfontw) que permite definir algumas das características da fonte.

*Charformat*<br/>
Um ponteiro para uma estrutura de dados [CHARFORMAT](/windows/win32/api/richedit/ns-richedit-charformata) que permite definir algumas das características da fonte em um rico controle de edição.

*dwFlags*<br/>
Especifica um ou mais sinalizadores de escolha de fonte. Um ou mais valores predefinidos podem ser combinados usando o operador bit a bit OR. Se você modificar o membro da estrutura `m_cf.Flag`, certifique-se de usar um operador bit a bit OR em suas alterações para manter o comportamento padrão intacto. Para obter detalhes sobre cada uma dessas bandeiras, consulte a descrição da estrutura [CHOOSEFONT](/windows/win32/api/commdlg/ns-commdlg-choosefontw) no SDK do Windows.

*pdcPrinter*<br/>
Um ponteiro para um contexto de dispositivo de impressão. Se fornecido, esse parâmetro apontará para um contexto de dispositivo de impressão para a impressora na qual as fontes serão selecionadas.

*Pparentwnd*<br/>
Um ponteiro para a janela pai ou proprietária da caixa de diálogo da fonte.

### <a name="remarks"></a>Comentários

Observe que o construtor preenche automaticamente os membros da estrutura `CHOOSEFONT`. Você só deve alterar isso se quiser um diálogo de fonte diferente do padrão.

> [!NOTE]
> A primeira versão dessa função só existe quando não há suporte para controle de edição com formato.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#78](../../mfc/codesnippet/cpp/cfontdialog-class_1.cpp)]

## <a name="cfontdialogdomodal"></a><a name="domodal"></a>CFontDialog::DoModal

Chame esta função para exibir a caixa de diálogo de fonte comum do Windows e permitir que o usuário escolha uma fonte.

```
virtual INT_PTR DoModal();
```

### <a name="return-value"></a>Valor retornado

IDOK ou IDCANCEL. Se o IDCANCEL for retornado, ligue para a função [CommDlgExtendedError](/windows/win32/api/commdlg/nf-commdlg-commdlgextendederror) do Windows para determinar se ocorreu um erro.

IDOK e IDCANCEL são constantes que indicam se o usuário selecionou o botão OK ou Cancel.

### <a name="remarks"></a>Comentários

Se você quiser inicializar os vários controles de diálogo de fonte definindo `DoModal`membros da estrutura [m_cf,](#m_cf) você deve fazer isso antes de chamar, mas depois que o objeto de diálogo for construído.

Se `DoModal` retornar o IDOK, você pode ligar para outras funções de membro para recuperar as configurações ou informações inseridas pelo usuário na caixa de diálogo.

### <a name="example"></a>Exemplo

  Veja os exemplos de [CFontDialog::CFontDialog](#cfontdialog) e [CFontDialog::GetColor](#getcolor).

## <a name="cfontdialoggetcharformat"></a><a name="getcharformat"></a>cfontdialog::getCharformat

Recupera a formatação de caracteres da fonte selecionada.

```cpp
void GetCharFormat(CHARFORMAT& cf) const;
```

### <a name="parameters"></a>Parâmetros

*Cf*<br/>
Uma estrutura [CHARFORMAT](/windows/win32/api/richedit/ns-richedit-charformata) contendo informações sobre a formatação de caracteres da fonte selecionada.

## <a name="cfontdialoggetcolor"></a><a name="getcolor"></a>cfontdialog::getColor

Chame esta função para recuperar a cor da fonte selecionada.

```
COLORREF GetColor() const;
```

### <a name="return-value"></a>Valor retornado

A cor da fonte selecionada.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#79](../../mfc/codesnippet/cpp/cfontdialog-class_2.cpp)]

## <a name="cfontdialoggetcurrentfont"></a><a name="getcurrentfont"></a>cfontdialog::getCurrentfont

Chame esta função para atribuir as características da fonte selecionada atualmente aos membros de uma estrutura [LOGFONT.](/windows/win32/api/wingdi/ns-wingdi-logfontw)

```cpp
void GetCurrentFont(LPLOGFONT lplf);
```

### <a name="parameters"></a>Parâmetros

*Lplf*<br/>
Um ponteiro `LOGFONT` para uma estrutura.

### <a name="remarks"></a>Comentários

Outras `CFontDialog` funções de membro são fornecidas para acessar características individuais da fonte atual.

Se essa função for chamada durante uma chamada para [doModal,](#domodal)ela reameda a seleção atual no momento (o que o usuário vê ou mudou na caixa de diálogo). Se essa função for chamada `DoModal` após `DoModal` uma chamada para (somente se retornar iDOK), ela retorna o que o usuário realmente selecionou.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#80](../../mfc/codesnippet/cpp/cfontdialog-class_3.cpp)]

## <a name="cfontdialoggetfacename"></a><a name="getfacename"></a>cfontdialog::getFacename

Chame esta função para recuperar o nome facial da fonte selecionada.

```
CString GetFaceName() const;
```

### <a name="return-value"></a>Valor retornado

O nome da face da `CFontDialog` fonte selecionada na caixa de diálogo.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#81](../../mfc/codesnippet/cpp/cfontdialog-class_4.cpp)]

## <a name="cfontdialoggetsize"></a><a name="getsize"></a>cfontdialog::getSize

Chame esta função para recuperar o tamanho da fonte selecionada.

```
int GetSize() const;
```

### <a name="return-value"></a>Valor retornado

O tamanho da fonte, em décimos de ponto.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#82](../../mfc/codesnippet/cpp/cfontdialog-class_5.cpp)]

## <a name="cfontdialoggetstylename"></a><a name="getstylename"></a>cfontdialog::getStyleName

Chame esta função para recuperar o nome de estilo da fonte selecionada.

```
CString GetStyleName() const;
```

### <a name="return-value"></a>Valor retornado

O nome de estilo da fonte.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#83](../../mfc/codesnippet/cpp/cfontdialog-class_6.cpp)]

## <a name="cfontdialoggetweight"></a><a name="getweight"></a>cfontdialog::getweight

Chame esta função para recuperar o peso da fonte selecionada.

```
int GetWeight() const;
```

### <a name="return-value"></a>Valor retornado

O peso da fonte selecionada.

### <a name="remarks"></a>Comentários

Para obter mais informações sobre o peso de uma fonte, consulte [CFont::CreateFont](../../mfc/reference/cfont-class.md#createfont).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#84](../../mfc/codesnippet/cpp/cfontdialog-class_7.cpp)]

## <a name="cfontdialogisbold"></a><a name="isbold"></a>cfontdialog::isbold

Chame esta função para determinar se a fonte selecionada está em negrito.

```
BOOL IsBold() const;
```

### <a name="return-value"></a>Valor retornado

Não zero se a fonte selecionada tiver a característica Bold ativada; caso contrário, 0.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#85](../../mfc/codesnippet/cpp/cfontdialog-class_8.cpp)]

## <a name="cfontdialogisitalic"></a><a name="isitalic"></a>cfontdialog::isitalic

Chame esta função para determinar se a fonte selecionada é itálica.

```
BOOL IsItalic() const;
```

### <a name="return-value"></a>Valor retornado

Não zero se a fonte selecionada tiver a característica itálica ativada; caso contrário, 0.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#86](../../mfc/codesnippet/cpp/cfontdialog-class_9.cpp)]

## <a name="cfontdialogisstrikeout"></a><a name="isstrikeout"></a>cfontdialog::isstrikeout

Chame esta função para determinar se a fonte selecionada é exibida com strikeout.

```
BOOL IsStrikeOut() const;
```

### <a name="return-value"></a>Valor retornado

Não zero se a fonte selecionada tiver a característica Strikeout ativada; caso contrário, 0.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#87](../../mfc/codesnippet/cpp/cfontdialog-class_10.cpp)]

## <a name="cfontdialogisunderline"></a><a name="isunderline"></a>cfontdialog::isUnderline

Ligue para esta função para determinar se a fonte selecionada está sublinhada.

```
BOOL IsUnderline() const;
```

### <a name="return-value"></a>Valor retornado

Não zero se a fonte selecionada tiver a característica Sublinhar ativada; caso contrário, 0.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#88](../../mfc/codesnippet/cpp/cfontdialog-class_11.cpp)]

## <a name="cfontdialogm_cf"></a><a name="m_cf"></a>cFontDialog::m_cf

Uma estrutura cujos membros armazenam as características do objeto de diálogo.

```
CHOOSEFONT m_cf;
```

### <a name="remarks"></a>Comentários

Depois de `CFontDialog` construir um objeto, você pode usar `m_cf` para modificar `DoModal` vários aspectos da caixa de diálogo antes de chamar a função de membro. Para obter mais informações sobre esta estrutura, consulte [CHOOSEFONT](/windows/win32/api/commdlg/ns-commdlg-choosefontw) no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#89](../../mfc/codesnippet/cpp/cfontdialog-class_12.cpp)]

## <a name="see-also"></a>Confira também

[Amostra de MFC HIERSVR](../../overview/visual-cpp-samples.md)<br/>
[Classe CCommonDialog](../../mfc/reference/ccommondialog-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)
