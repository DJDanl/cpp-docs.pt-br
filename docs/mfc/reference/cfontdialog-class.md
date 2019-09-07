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
ms.openlocfilehash: c0d0c37d055d9b337f7b709b4ee3d299daae7658
ms.sourcegitcommit: 180f63704f6ddd07a4172a93b179cf0733fd952d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/06/2019
ms.locfileid: "70741553"
---
# <a name="cfontdialog-class"></a>Classe CFontDialog

Permite que você incorpore uma caixa de diálogo de seleção de fonte em seu aplicativo.

## <a name="syntax"></a>Sintaxe

```
class CFontDialog : public CCommonDialog
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CFontDialog::CFontDialog](#cfontdialog)|Constrói um objeto `CFontDialog`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CFontDialog::DoModal](#domodal)|Exibe a caixa de diálogo e permite que o usuário faça uma seleção.|
|[CFontDialog::GetCharFormat](#getcharformat)|Recupera a formatação de caractere da fonte selecionada.|
|[CFontDialog::GetColor](#getcolor)|Retorna a cor da fonte selecionada.|
|[CFontDialog::GetCurrentFont](#getcurrentfont)|Atribui as características da fonte selecionada no momento a uma `LOGFONT` estrutura.|
|[CFontDialog::GetFaceName](#getfacename)|Retorna o nome da face da fonte selecionada.|
|[CFontDialog::GetSize](#getsize)|Retorna o tamanho do ponto da fonte selecionada.|
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

Um `CFontDialog` objeto é uma caixa de diálogo com uma lista de fontes que estão atualmente instaladas no sistema. O usuário pode selecionar uma fonte específica na lista e essa seleção é relatada de volta para o aplicativo.

Para construir um `CFontDialog` objeto, use o construtor fornecido ou derive uma nova subclasse e use seu próprio construtor personalizado.

Depois que `CFontDialog` um objeto tiver sido construído, você poderá usar `m_cf` a estrutura para inicializar os valores ou os Estados dos controles na caixa de diálogo. A estrutura [m_cf](#m_cf) é do tipo [ChooseFont](/windows/win32/api/commdlg/ns-commdlg-choosefontw). Para obter mais informações sobre essa estrutura, consulte a SDK do Windows.

Depois de inicializar os controles do objeto de diálogo, `DoModal` chame a função de membro para exibir a caixa de diálogo e permitir que o usuário selecione uma fonte. `DoModal`Retorna se o usuário selecionou o botão OK (IDOK) ou Cancel (IDCANCEL).

Se `DoModal` retornar IDOK, você poderá usar uma das `CFontDialog`funções de membro para recuperar a entrada de informações pelo usuário.

Você pode usar a função [CommDlgExtendedError](/windows/win32/api/commdlg/nf-commdlg-commdlgextendederror) do Windows para determinar se ocorreu um erro durante a inicialização da caixa de diálogo e para saber mais sobre o erro. Para obter mais informações sobre essa função, consulte a SDK do Windows.

`CFontDialog`depende do COMMDLG. Arquivo DLL fornecido com o Windows versões 3,1 e posteriores.

Para personalizar a caixa de diálogo, derive uma `CFontDialog`classe de, forneça um modelo de caixa de diálogo personalizado e adicione um mapa de mensagem para processar as mensagens de notificação dos controles estendidos. Todas as mensagens não processadas devem ser passadas para a classe base.

A personalização da função Hook não é necessária.

Para obter mais informações sobre `CFontDialog`como usar o, consulte [classes de caixa de diálogo comuns](../../mfc/common-dialog-classes.md).

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

*plfInitial*<br/>
Um ponteiro para uma estrutura de dados [LOGFONT](/windows/win32/api/wingdi/ns-wingdi-logfontw) que permite que você defina algumas das características da fonte.

*charFormat*<br/>
Um ponteiro para uma estrutura de dados [CHARFORMAT](/windows/win32/api/richedit/ns-richedit-charformata) que permite que você defina algumas das características da fonte em um controle de edição rico.

*dwFlags*<br/>
Especifica um ou mais sinalizadores de escolha de fonte. Um ou mais valores predefinidos podem ser combinados usando o operador bit a bit OR. Se você modificar o membro da estrutura `m_cf.Flag`, certifique-se de usar um operador bit a bit OR em suas alterações para manter o comportamento padrão intacto. Para obter detalhes sobre cada um desses sinalizadores, consulte a descrição da estrutura [ChooseFont](/windows/win32/api/commdlg/ns-commdlg-choosefontw) no SDK do Windows.

*pdcPrinter*<br/>
Um ponteiro para um contexto de dispositivo de impressão. Se fornecido, esse parâmetro apontará para um contexto de dispositivo de impressão para a impressora na qual as fontes serão selecionadas.

*pParentWnd*<br/>
Um ponteiro para a janela pai ou proprietária da caixa de diálogo da fonte.

### <a name="remarks"></a>Comentários

Observe que o construtor preenche automaticamente os membros da estrutura `CHOOSEFONT`. Você só deve alterar isso se quiser um diálogo de fonte diferente do padrão.

> [!NOTE]
>  A primeira versão dessa função só existe quando não há suporte para controle de edição com formato.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#78](../../mfc/codesnippet/cpp/cfontdialog-class_1.cpp)]

##  <a name="domodal"></a>CFontDialog::D oModal

Chame essa função para exibir a caixa de diálogo fonte comum do Windows e permitir que o usuário escolha uma fonte.

```
virtual INT_PTR DoModal();
```

### <a name="return-value"></a>Valor de retorno

IDOK ou IDCANCEL. Se IDCANCEL for retornado, chame a função [CommDlgExtendedError](/windows/win32/api/commdlg/nf-commdlg-commdlgextendederror) do Windows para determinar se ocorreu um erro.

IDOK e IDCANCEL são constantes que indicam se o usuário selecionou o botão OK ou cancelar.

### <a name="remarks"></a>Comentários

Se você quiser inicializar os vários controles de caixa de diálogo de fonte definindo membros da estrutura [m_cf](#m_cf) , faça isso antes de chamar `DoModal`, mas depois que o objeto da caixa de diálogo for construído.

Se `DoModal` retornar IDOK, você poderá chamar outras funções de membro para recuperar as configurações ou as informações inseridas pelo usuário na caixa de diálogo.

### <a name="example"></a>Exemplo

  Consulte os exemplos para [CFontDialog:: CFontDialog](#cfontdialog) e [CFontDialog:: GetColor](#getcolor).

##  <a name="getcharformat"></a>  CFontDialog::GetCharFormat

Recupera a formatação de caractere da fonte selecionada.

```
void GetCharFormat(CHARFORMAT& cf) const;
```

### <a name="parameters"></a>Parâmetros

*cf*<br/>
Uma estrutura [CHARFORMAT](/windows/win32/api/richedit/ns-richedit-charformata) que contém informações sobre a formatação de caractere da fonte selecionada.

##  <a name="getcolor"></a>  CFontDialog::GetColor

Chame essa função para recuperar a cor da fonte selecionada.

```
COLORREF GetColor() const;
```

### <a name="return-value"></a>Valor de retorno

A cor da fonte selecionada.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#79](../../mfc/codesnippet/cpp/cfontdialog-class_2.cpp)]

##  <a name="getcurrentfont"></a>  CFontDialog::GetCurrentFont

Chame essa função para atribuir as características da fonte selecionada no momento aos membros de uma estrutura [LOGFONT](/windows/win32/api/wingdi/ns-wingdi-logfontw) .

```
void GetCurrentFont(LPLOGFONT lplf);
```

### <a name="parameters"></a>Parâmetros

*lplf*<br/>
Um ponteiro para uma `LOGFONT` estrutura.

### <a name="remarks"></a>Comentários

Outras `CFontDialog` funções de membro são fornecidas para acessar características individuais da fonte atual.

Se essa função for chamada durante uma chamada para [DoModal](#domodal), ela retornará a seleção atual no momento (o que o usuário vê ou alterou na caixa de diálogo). Se essa função for chamada depois de uma chamada `DoModal` para (somente `DoModal` se retornar IDOK), ela retornará o que o usuário realmente selecionou.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#80](../../mfc/codesnippet/cpp/cfontdialog-class_3.cpp)]

##  <a name="getfacename"></a>  CFontDialog::GetFaceName

Chame essa função para recuperar o nome da face da fonte selecionada.

```
CString GetFaceName() const;
```

### <a name="return-value"></a>Valor de retorno

O nome da face da fonte selecionada na `CFontDialog` caixa de diálogo.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#81](../../mfc/codesnippet/cpp/cfontdialog-class_4.cpp)]

##  <a name="getsize"></a>  CFontDialog::GetSize

Chame essa função para recuperar o tamanho da fonte selecionada.

```
int GetSize() const;
```

### <a name="return-value"></a>Valor de retorno

O tamanho da fonte, em décimos de um ponto.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#82](../../mfc/codesnippet/cpp/cfontdialog-class_5.cpp)]

##  <a name="getstylename"></a>  CFontDialog::GetStyleName

Chame essa função para recuperar o nome do estilo da fonte selecionada.

```
CString GetStyleName() const;
```

### <a name="return-value"></a>Valor de retorno

O nome do estilo da fonte.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#83](../../mfc/codesnippet/cpp/cfontdialog-class_6.cpp)]

##  <a name="getweight"></a>  CFontDialog::GetWeight

Chame essa função para recuperar o peso da fonte selecionada.

```
int GetWeight() const;
```

### <a name="return-value"></a>Valor de retorno

O peso da fonte selecionada.

### <a name="remarks"></a>Comentários

Para obter mais informações sobre o peso de uma fonte, consulte [CFont:: CreateFont](../../mfc/reference/cfont-class.md#createfont).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#84](../../mfc/codesnippet/cpp/cfontdialog-class_7.cpp)]

##  <a name="isbold"></a>  CFontDialog::IsBold

Chame essa função para determinar se a fonte selecionada está em negrito.

```
BOOL IsBold() const;
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a fonte selecionada tiver a característica em negrito habilitada; caso contrário, 0.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#85](../../mfc/codesnippet/cpp/cfontdialog-class_8.cpp)]

##  <a name="isitalic"></a>  CFontDialog::IsItalic

Chame essa função para determinar se a fonte selecionada está em itálico.

```
BOOL IsItalic() const;
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a fonte selecionada tiver a característica em itálico habilitada; caso contrário, 0.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#86](../../mfc/codesnippet/cpp/cfontdialog-class_9.cpp)]

##  <a name="isstrikeout"></a>  CFontDialog::IsStrikeOut

Chame essa função para determinar se a fonte selecionada é exibida com riscado.

```
BOOL IsStrikeOut() const;
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a fonte selecionada tiver a característica de riscado habilitada; caso contrário, 0.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#87](../../mfc/codesnippet/cpp/cfontdialog-class_10.cpp)]

##  <a name="isunderline"></a>  CFontDialog::IsUnderline

Chame essa função para determinar se a fonte selecionada está sublinhada.

```
BOOL IsUnderline() const;
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a fonte selecionada tiver a característica de sublinhada habilitada; caso contrário, 0.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#88](../../mfc/codesnippet/cpp/cfontdialog-class_11.cpp)]

##  <a name="m_cf"></a>  CFontDialog::m_cf

Uma estrutura cujos membros armazenam as características do objeto da caixa de diálogo.

```
CHOOSEFONT m_cf;
```

### <a name="remarks"></a>Comentários

Depois de construir um `CFontDialog` objeto, você pode usar `m_cf` para modificar vários aspectos da caixa de diálogo antes de chamar `DoModal` a função de membro. Para obter mais informações sobre essa estrutura, consulte [ChooseFont](/windows/win32/api/commdlg/ns-commdlg-choosefontw) no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#89](../../mfc/codesnippet/cpp/cfontdialog-class_12.cpp)]

## <a name="see-also"></a>Consulte também

[Exemplo de HIERSVR do MFC](../../overview/visual-cpp-samples.md)<br/>
[Classe CCommonDialog](../../mfc/reference/ccommondialog-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)
