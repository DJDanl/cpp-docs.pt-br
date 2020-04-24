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
ms.openlocfilehash: 99b4ff27a7686972bcbc85478998b52ed713ab5b
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81754262"
---
# <a name="ccolordialog-class"></a>Classe CColorDialog

Permite incorporar uma caixa de diálogo de seleção de cores em seu aplicativo.

## <a name="syntax"></a>Sintaxe

```
class CColorDialog : public CCommonDialog
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[ccolordia::CColorDialog](#ccolordialog)|Constrói um objeto `CColorDialog`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CColorDialog::DoModal](#domodal)|Exibe uma caixa de diálogo de cor e permite que o usuário faça uma seleção.|
|[ccolordialog::getColor](#getcolor)|Retorna `COLORREF` uma estrutura contendo os valores da cor selecionada.|
|[ccolordiálogo::obtercores personalizadas salvas](#getsavedcustomcolors)|Recupera cores personalizadas criadas pelo usuário.|
|[cColorDialog::SetCurrentColor](#setcurrentcolor)|Força a seleção de cores atual à cor especificada.|

### <a name="protected-methods"></a>Métodos Protegidos

|Nome|Descrição|
|----------|-----------------|
|[ccolordia::OnColorOK](#oncolorok)|Substituir para validar a cor inserida na caixa de diálogo.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[cColordialog::m_cc](#m_cc)|Uma estrutura usada para personalizar as configurações da caixa de diálogo.|

## <a name="remarks"></a>Comentários

Um `CColorDialog` objeto é uma caixa de diálogo com uma lista de cores definidas para o sistema de exibição. O usuário pode selecionar ou criar uma cor específica da lista, que é então relatada de volta ao aplicativo quando a caixa de diálogo sai.

Para construir `CColorDialog` um objeto, use o construtor fornecido ou obtenha uma nova classe e use seu próprio construtor personalizado.

Uma vez que a caixa de diálogo tenha sido construída, você pode definir ou modificar quaisquer valores na estrutura [m_cc](#m_cc) para inicializar os valores dos controles da caixa de diálogo. A estrutura *m_cc* é do tipo [CHOOSECOLOR](/windows/win32/api/commdlg/ns-commdlg-choosecolora~r1).

Depois de inicializar os controles da `DoModal` caixa de diálogo, ligue para a função do membro para exibir a caixa de diálogo e permita que o usuário selecione uma cor. `DoModal`retorna a seleção do usuário do botão OK (IDOK) ou Cancelar (IDCANCEL) da caixa de diálogo.

Se `DoModal` retornar o IDOK, `CColorDialog`você pode usar uma das funções de membro para recuperar a entrada de informações pelo usuário.

Você pode usar a função Windows [CommDlgExtendedError](/windows/win32/api/commdlg/nf-commdlg-commdlgextendederror) para determinar se ocorreu um erro durante a inicialização da caixa de diálogo e para saber mais sobre o erro.

`CColorDialog`conta com o COMMDLG. Arquivo DLL que é fornecido com as versões 3.1 do Windows e posteriores.

Para personalizar a caixa de `CColorDialog`diálogo, obtenha uma classe, forneça um modelo de diálogo personalizado e adicione um mapa de mensagem para processar as mensagens de notificação dos controles estendidos. Quaisquer mensagens não processadas devem ser passadas para a classe base.

Personalizar a função do gancho não é necessário.

> [!NOTE]
> Em algumas instalações, o `CColorDialog` objeto não será exibido com um `CDialog` fundo cinza se você tiver usado a estrutura para fazer outros objetos cinzas.

Para obter mais `CColorDialog`informações sobre como usar, consulte [Classes de diálogo comuns](../../mfc/common-dialog-classes.md)

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[Cdialog](../../mfc/reference/cdialog-class.md)

[Ccommondialog](../../mfc/reference/ccommondialog-class.md)

`CColorDialog`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdlgs.h

## <a name="ccolordialogccolordialog"></a><a name="ccolordialog"></a>ccolordia::CColorDialog

Constrói um objeto `CColorDialog`.

```
CColorDialog(
    COLORREF clrInit = 0,
    DWORD dwFlags = 0,
    CWnd* pParentWnd = NULL);
```

### <a name="parameters"></a>Parâmetros

*clrInit*<br/>
A seleção padrão de cores. Se nenhum valor for especificado, o padrão será RGB(0,0,0) (preto).

*dwFlags*<br/>
Um conjunto de sinalizadores que personalizam a função e a aparência da caixa de diálogo. Para obter mais informações, consulte a estrutura [CHOOSECOLOR](/windows/win32/api/commdlg/ns-commdlg-choosecolora~r1) no SDK do Windows.

*Pparentwnd*<br/>
Um ponteiro para a janela pai ou proprietário da caixa de diálogo.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#49](../../mfc/codesnippet/cpp/ccolordialog-class_1.cpp)]

## <a name="ccolordialogdomodal"></a><a name="domodal"></a>CColorDialog::DoModal

Chame esta função para exibir a caixa de diálogo de cor comum do Windows e permitir que o usuário selecione uma cor.

```
virtual INT_PTR DoModal();
```

### <a name="return-value"></a>Valor retornado

IDOK ou IDCANCEL. Se o IDCANCEL for retornado, ligue para a função [CommDlgExtendedError](/windows/win32/api/commdlg/nf-commdlg-commdlgextendederror) do Windows para determinar se ocorreu um erro.

IDOK e IDCANCEL são constantes que indicam se o usuário selecionou o botão OK ou Cancel.

### <a name="remarks"></a>Comentários

Se você quiser inicializar as várias opções de caixa de diálogo de `DoModal` cor definindo membros da estrutura [m_cc,](#m_cc) você deve fazer isso antes de chamar, mas depois que o objeto caixa de diálogo for construído.

Depois `DoModal`de ligar, você pode ligar para outras funções de membro para recuperar as configurações ou informações inseridas pelo usuário na caixa de diálogo.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CColorDialog::CColorDialog](#ccolordialog).

## <a name="ccolordialoggetcolor"></a><a name="getcolor"></a>ccolordialog::getColor

Ligue para esta `DoModal` função depois de ligar para recuperar as informações sobre a cor que o usuário selecionou.

```
COLORREF GetColor() const;
```

### <a name="return-value"></a>Valor retornado

Um [valor COLORREF](/windows/win32/gdi/colorref) que contém as informações RGB para a cor selecionada na caixa de diálogo de cor.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#50](../../mfc/codesnippet/cpp/ccolordialog-class_2.cpp)]

## <a name="ccolordialoggetsavedcustomcolors"></a><a name="getsavedcustomcolors"></a>ccolordiálogo::obtercores personalizadas salvas

`CColorDialog`objetos permitem que o usuário, além de escolher cores, defina até 16 cores personalizadas.

```
static COLORREF* PASCAL GetSavedCustomColors();
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para uma matriz de 16 valores de cor RGB que armazena cores personalizadas criadas pelo usuário.

### <a name="remarks"></a>Comentários

A `GetSavedCustomColors` função de membro fornece acesso a essas cores. Essas cores podem ser recuperadas após o Retorno do IDOK do [DoModal.](#domodal)

Cada um dos 16 valores RGB na matriz retornada é inicializado em RGB (255.255.255) (branco). As cores personalizadas escolhidas pelo usuário são salvas apenas entre invocações de caixa de diálogo dentro do aplicativo. Se você deseja salvar essas cores entre invocações do aplicativo, você deve salvá-las de alguma outra maneira, como em uma inicialização (. ARQUIVO INI.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#51](../../mfc/codesnippet/cpp/ccolordialog-class_3.cpp)]

## <a name="ccolordialogm_cc"></a><a name="m_cc"></a>cColordialog::m_cc

Uma estrutura do tipo [CHOOSECOLOR](/windows/win32/api/commdlg/ns-commdlg-choosecolora~r1), cujos membros armazenam as características e valores da caixa de diálogo.

```
CHOOSECOLOR m_cc;
```

### <a name="remarks"></a>Comentários

Depois de `CColorDialog` construir um objeto, você pode usar *m_cc* para definir vários aspectos da caixa de diálogo antes de chamar a função de membro [DoModal.](#domodal)

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#53](../../mfc/codesnippet/cpp/ccolordialog-class_4.cpp)]

## <a name="ccolordialogoncolorok"></a><a name="oncolorok"></a>ccolordia::OnColorOK

Substituir para validar a cor inserida na caixa de diálogo.

```
virtual BOOL OnColorOK();
```

### <a name="return-value"></a>Valor retornado

Não zero se a caixa de diálogo não for descartada; caso contrário 0 para aceitar a cor que foi inserida.

### <a name="remarks"></a>Comentários

Anular esta função somente se você quiser fornecer validação personalizada da cor que o usuário seleciona na caixa de diálogo de cor.

O usuário pode selecionar uma cor por um dos dois métodos a seguir:

- Clicando em uma cor na paleta de cores. Os valores RGB da cor selecionada são então refletidos nas caixas de edição RGB apropriadas.

- Inserindo valores nas caixas de edição RGB

A `OnColorOK` substituição permite que você rejeite uma cor que o usuário entra em uma caixa de diálogo de cor comum por qualquer motivo específico do aplicativo.

Normalmente, você não precisa usar essa função porque a estrutura fornece validação padrão de cores e exibe uma caixa de mensagem se uma cor inválida for inserida.

Você pode chamar [SetCurrentColor](#setcurrentcolor) de dentro `OnColorOK` para forçar uma seleção de cores. Uma `OnColorOK` vez demitido (ou seja, o usuário clica em **OK** para aceitar a mudança de cor), você pode chamar [GetColor](#getcolor) para obter o valor RGB da nova cor.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#52](../../mfc/codesnippet/cpp/ccolordialog-class_5.cpp)]

## <a name="ccolordialogsetcurrentcolor"></a><a name="setcurrentcolor"></a>cColorDialog::SetCurrentColor

Chame esta função `DoModal` após a chamada para forçar a seleção de cores atual para o valor de cor especificado em *clr*.

```cpp
void SetCurrentColor(COLORREF clr);
```

### <a name="parameters"></a>Parâmetros

*Clr*<br/>
Um valor de cor RGB.

### <a name="remarks"></a>Comentários

Esta função é chamada de `OnColorOK`dentro de um manipulador de mensagens ou . A caixa de diálogo atualizará automaticamente a seleção do usuário com base no valor do parâmetro *clr.*

### <a name="example"></a>Exemplo

  Veja o exemplo de [CColorDialog::OnColorOK](#oncolorok).

## <a name="see-also"></a>Confira também

[MDI amostra MFC](../../overview/visual-cpp-samples.md)<br/>
[Amostra de MFC DRAWCLI](../../overview/visual-cpp-samples.md)<br/>
[Classe CCommonDialog](../../mfc/reference/ccommondialog-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)
