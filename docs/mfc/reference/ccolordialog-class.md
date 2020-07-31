---
title: Classe CColorDialog
ms.date: 11/04/2016
f1_keywords:
- CColorDialog
- AFXDLGS/CColorDialog
- AFXDLGS/CColorDialog::CColorDialog
- AFXDLGS/CColorDialog::DoModal
- AFXDLGS/CColorDialog::GetColor
- AFXDLGS/CColorDialog::GetSavedCustomColors
- AFXDLGS/CColorDialog::SetCurrentColor
- AFXDLGS/CColorDialog::OnColorOK
- AFXDLGS/CColorDialog::m_cc
helpviewer_keywords:
- CColorDialog [MFC], CColorDialog
- CColorDialog [MFC], DoModal
- CColorDialog [MFC], GetColor
- CColorDialog [MFC], GetSavedCustomColors
- CColorDialog [MFC], SetCurrentColor
- CColorDialog [MFC], OnColorOK
- CColorDialog [MFC], m_cc
ms.assetid: d013dc25-9290-4b5d-a97e-95ad7208e13b
ms.openlocfilehash: 54fd987d683a9236531baee3afbb9ee61be623e2
ms.sourcegitcommit: 13f42c339fb7af935e3a93ac80e350d5e784c9f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/31/2020
ms.locfileid: "87470752"
---
# <a name="ccolordialog-class"></a>Classe CColorDialog

Permite incorporar uma caixa de diálogo de seleção de cor em seu aplicativo.

## <a name="syntax"></a>Syntax

```
class CColorDialog : public CCommonDialog
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Name|Descrição|
|----------|-----------------|
|[CColorDialog::CColorDialog](#ccolordialog)|Constrói um objeto `CColorDialog`.|

### <a name="public-methods"></a>Métodos públicos

|Name|Descrição|
|----------|-----------------|
|[CColorDialog::D oModal](#domodal)|Exibe uma caixa de diálogo cor e permite que o usuário faça uma seleção.|
|[CColorDialog:: GetColor](#getcolor)|Retorna uma `COLORREF` estrutura que contém os valores da cor selecionada.|
|[CColorDialog::GetSavedCustomColors](#getsavedcustomcolors)|Recupera cores personalizadas criadas pelo usuário.|
|[CColorDialog::SetCurrentColor](#setcurrentcolor)|Força a seleção de cor atual à cor especificada.|

### <a name="protected-methods"></a>Métodos Protegidos

|Name|Descrição|
|----------|-----------------|
|[CColorDialog::OnColorOK](#oncolorok)|Substitua para validar a cor inserida na caixa de diálogo.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Name|Descrição|
|----------|-----------------|
|[CColorDialog:: m_cc](#m_cc)|Uma estrutura usada para personalizar as configurações da caixa de diálogo.|

## <a name="remarks"></a>Comentários

Um `CColorDialog` objeto é uma caixa de diálogo com uma lista de cores que são definidas para o sistema de vídeo. O usuário pode selecionar ou criar uma cor específica na lista, que é relatada de volta ao aplicativo quando a caixa de diálogo é encerrada.

Para construir um `CColorDialog` objeto, use o construtor fornecido ou derive uma nova classe e use seu próprio construtor personalizado.

Depois que a caixa de diálogo tiver sido construída, você poderá definir ou modificar quaisquer valores na estrutura de [m_cc](#m_cc) para inicializar os valores dos controles da caixa de diálogo. A estrutura de *m_cc* é do tipo [CHOOSECOLOR](/windows/win32/api/commdlg/ns-commdlg-choosecolora-r1).

Depois de inicializar os controles da caixa de diálogo, chame a `DoModal` função de membro para exibir a caixa de diálogo e permitir que o usuário selecione uma cor. `DoModal`Retorna a seleção do usuário do botão OK (IDOK) ou Cancel (IDCANCEL) da caixa de diálogo.

Se `DoModal` retornar IDOK, você poderá usar uma das `CColorDialog` funções de membro para recuperar a entrada de informações pelo usuário.

Você pode usar a função [CommDlgExtendedError](/windows/win32/api/commdlg/nf-commdlg-commdlgextendederror) do Windows para determinar se ocorreu um erro durante a inicialização da caixa de diálogo e para saber mais sobre o erro.

`CColorDialog`o se baseia no arquivo de COMMDLG.DLL fornecido com as versões 3,1 e posteriores do Windows.

Para personalizar a caixa de diálogo, derive uma classe de `CColorDialog` , forneça um modelo de caixa de diálogo personalizado e adicione um mapa de mensagens para processar as mensagens de notificação dos controles estendidos. Todas as mensagens não processadas devem ser passadas para a classe base.

A personalização da função Hook não é necessária.

> [!NOTE]
> Em algumas instalações `CColorDialog` , o objeto não será exibido com um plano de fundo cinza se você tiver usado a estrutura para tornar outros `CDialog` objetos cinzas.

Para obter mais informações sobre como usar o `CColorDialog` , consulte [classes de diálogo comuns](../../mfc/common-dialog-classes.md)

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CDialog](../../mfc/reference/cdialog-class.md)

[CCommonDialog](../../mfc/reference/ccommondialog-class.md)

`CColorDialog`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdlgs. h

## <a name="ccolordialogccolordialog"></a><a name="ccolordialog"></a>CColorDialog::CColorDialog

Constrói um objeto `CColorDialog`.

```
CColorDialog(
    COLORREF clrInit = 0,
    DWORD dwFlags = 0,
    CWnd* pParentWnd = NULL);
```

### <a name="parameters"></a>Parâmetros

*clrInit*<br/>
A seleção de cor padrão. Se nenhum valor for especificado, o padrão será RGB (0, 0, 0) (preto).

*dwFlags*<br/>
Um conjunto de sinalizadores que personalizam a função e a aparência da caixa de diálogo. Para obter mais informações, consulte a estrutura [CHOOSECOLOR](/windows/win32/api/commdlg/ns-commdlg-choosecolora-r1) no SDK do Windows.

*pParentWnd*<br/>
Um ponteiro para a janela pai ou proprietário da caixa de diálogo.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#49](../../mfc/codesnippet/cpp/ccolordialog-class_1.cpp)]

## <a name="ccolordialogdomodal"></a><a name="domodal"></a>CColorDialog::D oModal

Chame essa função para exibir a caixa de diálogo cor comum do Windows e permitir que o usuário selecione uma cor.

```
virtual INT_PTR DoModal();
```

### <a name="return-value"></a>Valor Retornado

IDOK ou IDCANCEL. Se IDCANCEL for retornado, chame a função [CommDlgExtendedError](/windows/win32/api/commdlg/nf-commdlg-commdlgextendederror) do Windows para determinar se ocorreu um erro.

IDOK e IDCANCEL são constantes que indicam se o usuário selecionou o botão OK ou cancelar.

### <a name="remarks"></a>Comentários

Se você quiser inicializar as várias opções de caixa de diálogo de cor definindo membros da estrutura de [m_cc](#m_cc) , faça isso antes de chamar, `DoModal` mas depois que o objeto da caixa de diálogo for construído.

Depois de chamar `DoModal` , você pode chamar outras funções de membro para recuperar as configurações ou as informações inseridas pelo usuário na caixa de diálogo.

### <a name="example"></a>Exemplo

  Consulte o exemplo de [CColorDialog:: CColorDialog](#ccolordialog).

## <a name="ccolordialoggetcolor"></a><a name="getcolor"></a>CColorDialog:: GetColor

Chame essa função depois de chamar `DoModal` para recuperar as informações sobre a cor que o usuário selecionou.

```
COLORREF GetColor() const;
```

### <a name="return-value"></a>Valor Retornado

Um valor de [COLORREF](/windows/win32/gdi/colorref) que contém as informações RGB para a cor selecionada na caixa de diálogo cor.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#50](../../mfc/codesnippet/cpp/ccolordialog-class_2.cpp)]

## <a name="ccolordialoggetsavedcustomcolors"></a><a name="getsavedcustomcolors"></a>CColorDialog::GetSavedCustomColors

`CColorDialog`os objetos permitem que o usuário, além de escolher cores, defina até 16 cores personalizadas.

```
static COLORREF* PASCAL GetSavedCustomColors();
```

### <a name="return-value"></a>Valor Retornado

Um ponteiro para uma matriz de 16 valores de cor RGB que armazena cores personalizadas criadas pelo usuário.

### <a name="remarks"></a>Comentários

A `GetSavedCustomColors` função membro fornece acesso a essas cores. Essas cores podem ser recuperadas depois que [DoModal](#domodal) retorna IDOK.

Cada um dos 16 valores RGB na matriz retornada é inicializado como RGB (255255255) (branco). As cores personalizadas escolhidas pelo usuário são salvas somente entre as invocações da caixa de diálogo dentro do aplicativo. Se você quiser salvar essas cores entre invocações do aplicativo, você deve salvá-las de alguma outra maneira, como em uma inicialização (. INI).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#51](../../mfc/codesnippet/cpp/ccolordialog-class_3.cpp)]

## <a name="ccolordialogm_cc"></a><a name="m_cc"></a>CColorDialog:: m_cc

Uma estrutura do tipo [CHOOSECOLOR](/windows/win32/api/commdlg/ns-commdlg-choosecolora-r1), cujos membros armazenam as características e os valores da caixa de diálogo.

```
CHOOSECOLOR m_cc;
```

### <a name="remarks"></a>Comentários

Depois de construir um `CColorDialog` objeto, você pode usar *m_cc* para definir vários aspectos da caixa de diálogo antes de chamar a função de membro [DoModal](#domodal) .

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#53](../../mfc/codesnippet/cpp/ccolordialog-class_4.cpp)]

## <a name="ccolordialogoncolorok"></a><a name="oncolorok"></a>CColorDialog::OnColorOK

Substitua para validar a cor inserida na caixa de diálogo.

```
virtual BOOL OnColorOK();
```

### <a name="return-value"></a>Valor Retornado

Diferente de zero se a caixa de diálogo não deve ser descartada; caso contrário, 0 para aceitar a cor que foi inserida.

### <a name="remarks"></a>Comentários

Substitua essa função somente se desejar fornecer validação personalizada da cor que o usuário seleciona na caixa de diálogo cor.

O usuário pode selecionar uma cor de um dos dois métodos a seguir:

- Clicando em uma cor na paleta de cores. Os valores RGB da cor selecionada são refletidos nas caixas de edição RGB apropriadas.

- Inserindo valores nas caixas de edição RGB

`OnColorOK`A substituição permite rejeitar uma cor que o usuário insere em uma caixa de diálogo de cor comum para qualquer motivo específico do aplicativo.

Normalmente, você não precisa usar essa função porque a estrutura fornece validação padrão de cores e exibe uma caixa de mensagem se uma cor inválida for inserida.

Você pode chamar [SetCurrentColor](#setcurrentcolor) de dentro `OnColorOK` para forçar uma seleção de cor. Uma vez foi `OnColorOK` acionado (ou seja, o usuário clica em **OK** para aceitar a alteração de cor), você pode chamar [GetColor](#getcolor) para obter o valor RGB da nova cor.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#52](../../mfc/codesnippet/cpp/ccolordialog-class_5.cpp)]

## <a name="ccolordialogsetcurrentcolor"></a><a name="setcurrentcolor"></a>CColorDialog::SetCurrentColor

Chame essa função depois de chamar `DoModal` para forçar a seleção de cor atual para o valor de cor especificado em *CLR*.

```cpp
void SetCurrentColor(COLORREF clr);
```

### <a name="parameters"></a>Parâmetros

*CLR*<br/>
Um valor de cor RGB.

### <a name="remarks"></a>Comentários

Essa função é chamada de dentro de um manipulador de mensagens ou `OnColorOK` . A caixa de diálogo atualizará automaticamente a seleção do usuário com base no valor do parâmetro *CLR* .

### <a name="example"></a>Exemplo

  Consulte o exemplo de [CColorDialog:: OnColorOK](#oncolorok).

## <a name="see-also"></a>Veja também

[MDI de exemplo do MFC](../../overview/visual-cpp-samples.md)<br/>
[Exemplo de DRAWCLI do MFC](../../overview/visual-cpp-samples.md)<br/>
[Classe CCommonDialog](../../mfc/reference/ccommondialog-class.md)<br/>
[Gráfico de hierarquia](../../mfc/hierarchy-chart.md)
