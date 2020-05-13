---
title: Classe CDialog
ms.date: 09/07/2019
f1_keywords:
- CDialog
- AFXWIN/CDialog
- AFXWIN/CDialog::CDialog
- AFXWIN/CDialog::Create
- AFXWIN/CDialog::CreateIndirect
- AFXWIN/CDialog::DoModal
- AFXWIN/CDialog::EndDialog
- AFXWIN/CDialog::GetDefID
- AFXWIN/CDialog::GotoDlgCtrl
- AFXWIN/CDialog::InitModalIndirect
- AFXWIN/CDialog::MapDialogRect
- AFXWIN/CDialog::NextDlgCtrl
- AFXWIN/CDialog::OnInitDialog
- AFXWIN/CDialog::OnSetFont
- AFXWIN/CDialog::PrevDlgCtrl
- AFXWIN/CDialog::SetDefID
- AFXWIN/CDialog::SetHelpID
- AFXWIN/CDialog::OnCancel
- AFXWIN/CDialog::OnOK
helpviewer_keywords:
- CDialog [MFC], CDialog
- CDialog [MFC], Create
- CDialog [MFC], CreateIndirect
- CDialog [MFC], DoModal
- CDialog [MFC], EndDialog
- CDialog [MFC], GetDefID
- CDialog [MFC], GotoDlgCtrl
- CDialog [MFC], InitModalIndirect
- CDialog [MFC], MapDialogRect
- CDialog [MFC], NextDlgCtrl
- CDialog [MFC], OnInitDialog
- CDialog [MFC], OnSetFont
- CDialog [MFC], PrevDlgCtrl
- CDialog [MFC], SetDefID
- CDialog [MFC], SetHelpID
- CDialog [MFC], OnCancel
- CDialog [MFC], OnOK
ms.assetid: ca64b77e-2cd2-47e3-8eff-c2645ad578f9
ms.openlocfilehash: 36913cfdd8beda31136176c966890a90077c1b30
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81753371"
---
# <a name="cdialog-class"></a>Classe CDialog

A classe base usada para exibir caixas de diálogo na tela.

## <a name="syntax"></a>Sintaxe

```
class CDialog : public CWnd
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CDialog::CDialog](#cdialog)|Constrói um objeto `CDialog`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CDiálogo::Criar](#create)|Inicializa o objeto `CDialog`. Cria uma caixa de diálogo modeless `CDialog` e a anexa ao objeto.|
|[cdiálogo::Criar indireta](#createindirect)|Cria uma caixa de diálogo modeless a partir de um modelo de caixa de diálogo na memória (não baseada em recursos).|
|[CDialog::DoModal](#domodal)|Chama uma caixa de diálogo modal e retorna quando feito.|
|[cdiálogo::EndDialog](#enddialog)|Fecha uma caixa de diálogo modal.|
|[Diálogo::GetDefID](#getdefid)|Obtém o ID do controle de botão padrão para uma caixa de diálogo.|
|[CDialog::GotoDlgCtrl](#gotodlgctrl)|Move o foco para um controle de caixa de diálogo especificado na caixa de diálogo.|
|[CDialog::InitModalIndirect](#initmodalindirect)|Cria uma caixa de diálogo modal a partir de um modelo de caixa de diálogo na memória (não baseada em recursos). Os parâmetros são `DoModal` armazenados até que a função seja chamada.|
|[CDiálogo::MapDialogRect](#mapdialogrect)|Converte as unidades da caixa de diálogo de um retângulo em unidades de tela.|
|[CDialog::NextDlgCtrl](#nextdlgctrl)|Move o foco para o próximo controle da caixa de diálogo na caixa de diálogo.|
|[CDialog::OnInitDialog](#oninitdialog)|Substituir para aumentar a inicialização da caixa de diálogo.|
|[diálogo::Fonte de início](#onsetfont)|Substituir para especificar a fonte que um controle de caixa de diálogo deve usar quando ele desenha texto.|
|[CDialog::PrevDlgCtrl](#prevdlgctrl)|Move o foco para o controle anterior da caixa de diálogo na caixa de diálogo.|
|[CDialog::SetDefID](#setdefid)|Altera o controle de botão padrão para uma caixa de diálogo para um botão especificado.|
|[diálogo::sethelpid](#sethelpid)|Define um ID de ajuda sensível ao contexto para a caixa de diálogo.|

### <a name="protected-methods"></a>Métodos Protegidos

|Nome|Descrição|
|----------|-----------------|
|[cdialog::Oncancel](#oncancel)|Substituir para executar o botão Cancelar ou a ação chave ESC. O padrão fecha a `DoModal` caixa de diálogo e retorna IDCANCEL.|
|[cdialog::OnOK](#onok)|Substituir para executar a ação do botão OK em uma caixa de diálogo modal. O padrão fecha a `DoModal` caixa de diálogo e retorna o IDOK.|

## <a name="remarks"></a>Comentários

As caixas de diálogo são de dois tipos: modal e modelagem. Uma caixa de diálogo modal deve ser fechada pelo usuário antes que o aplicativo continue. Uma caixa de diálogo modeless permite que o usuário exiba a caixa de diálogo e retorne a outra tarefa sem cancelar ou remover a caixa de diálogo.

Um `CDialog` objeto é uma combinação de `CDialog`um modelo de diálogo e uma classe derivada. Use o editor de diálogo para criar o modelo de diálogo e armazená-lo `CDialog`em um recurso e, em seguida, use o assistente Adicionar classe para criar uma classe derivada de .

Uma caixa de diálogo, como qualquer outra janela, recebe mensagens do Windows. Em uma caixa de diálogo, você está particularmente interessado em manusear mensagens de notificação dos controles da caixa de diálogo, pois é assim que o usuário interage com sua caixa de diálogo. Use o [Assistente de Classe](mfc-class-wizard.md) para selecionar quais mensagens deseja manusear e adicionará as entradas apropriadas do mapa de mensagens e as funções de membro do manipulador de mensagens à classe para você. Você só precisa escrever código específico do aplicativo nas funções do membro do manipulador.

Se preferir, você pode sempre escrever entradas de mapa de mensagem e funções de membro manualmente.

Em todos, exceto na caixa de diálogo mais trivial, você adiciona variáveis de membro à sua classe de diálogo derivada para armazenar dados inseridos nos controles da caixa de diálogo pelo usuário ou para exibir dados para o usuário. Você pode usar o assistente Adicionar variável para criar variáveis de membro e associá-las a controles. Ao mesmo tempo, você escolhe um tipo variável e uma faixa de valores admissível para cada variável. O assistente de código adiciona as variáveis de membro à sua classe de diálogo derivada.

Um mapa de dados é gerado para lidar automaticamente com a troca de dados entre as variáveis membros e os controles da caixa de diálogo. O mapa de dados fornece funções que inicializam os controles na caixa de diálogo com os valores adequados, recuperam os dados e validam os dados.

Para criar uma caixa de diálogo modal, construa um objeto na pilha `DoModal` usando o construtor para sua classe de diálogo derivada e, em seguida, ligue para criar a janela de diálogo e seus controles. Se você deseja criar um diálogo `Create` de modelagem, chame o construtor da sua classe de diálogo.

Você também pode criar um modelo na memória usando uma estrutura de dados [DLGTEMPLATE](/windows/win32/api/winuser/ns-winuser-dlgtemplate) como descrito no SDK do Windows. Depois de `CDialog` construir um objeto, chame [CreateIndirect](#createindirect) para criar uma caixa de diálogo modeless ou chame [InitModalIndirect](#initmodalindirect) e [DoModal](#domodal) para criar uma caixa de diálogo modal.

O mapa de dados de troca e `CWnd::DoDataExchange` validação é gravado em uma substituição disso é adicionado à sua nova classe de diálogo. Consulte a função do `CWnd` membro [DoDataExchange](../../mfc/reference/cwnd-class.md#dodataexchange) para obter mais informações sobre a funcionalidade de troca e validação.

Tanto o programador quanto `DoDataExchange` o framework chamam indiretamente através de uma chamada para [CWnd::UpdateData](../../mfc/reference/cwnd-class.md#updatedata).

A estrutura `UpdateData` é chamada quando o usuário clica no botão OK para fechar uma caixa de diálogo modal. (Os dados não são recuperados se o botão Cancelar for clicado.) A implementação padrão do [OnInitDialog](#oninitdialog) também exige `UpdateData` definir os valores iniciais dos controles. Você normalmente `OnInitDialog` se sobrepor para inicializar ainda mais os controles. `OnInitDialog`é chamado depois que todos os controles de diálogo são criados e pouco antes da caixa de diálogo ser exibida.

Você pode `CWnd::UpdateData` ligar a qualquer momento durante a execução de uma caixa de diálogo modal ou modeless.

Se você desenvolver uma caixa de diálogo manualmente, você adicionará as variáveis de membro necessárias à classe de caixa de diálogo derivada e adicionará funções de membro para definir ou obter esses valores.

Uma caixa de diálogo modal fecha automaticamente quando o usuário pressiona os `EndDialog` botões OK ou Cancel ou quando seu código chama a função de membro.

Quando você implementa uma caixa de diálogo `OnCancel` modeless, substitua sempre a função do membro e ligue `DestroyWindow` de dentro dela. Não chame a classe `CDialog::OnCancel`base, `EndDialog`porque ela chama, o que tornará a caixa de diálogo invisível, mas não a destruirá. Você também deve `PostNcDestroy` substituir as caixas de diálogo modeless para excluir **isso,** uma vez que as caixas de diálogo modeless geralmente são alocadas com **novas**. As caixas de diálogo modais são geralmente `PostNcDestroy` construídas sobre o quadro e não precisam de limpeza.

Para obter `CDialog`mais informações, consulte [Caixas de diálogo](../../mfc/dialog-boxes.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

`CDialog`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxwin.h

## <a name="cdialogcdialog"></a><a name="cdialog"></a>CDialog::CDialog

Para construir uma caixa de diálogo modal baseada em recursos, chame a forma pública do construtor.

```
explicit CDialog(
    LPCTSTR lpszTemplateName,
    CWnd* pParentWnd = NULL);

explicit CDialog(
    UINT nIDTemplate,
    CWnd* pParentWnd = NULL);

CDialog();
```

### <a name="parameters"></a>Parâmetros

*lpszTemplateName*<br/>
Contém uma seqüência de seqüência de terminadas nula que é o nome de um recurso de modelo de caixa de diálogo.

*Nidtemplate*<br/>
Contém o número de ID de um recurso de modelo de caixa de diálogo.

*Pparentwnd*<br/>
Aponta para o objeto da janela pai ou proprietário (do tipo [CWnd)](../../mfc/reference/cwnd-class.md)ao qual o objeto de diálogo pertence. Se for NULL, a janela pai do objeto de diálogo será definida na janela principal do aplicativo.

### <a name="remarks"></a>Comentários

Uma forma do construtor fornece acesso ao recurso de diálogo pelo nome do modelo. O outro construtor fornece acesso por número de id de modelo, geralmente com um prefixo **IDD_** (por exemplo, IDD_DIALOG1).

Para construir uma caixa de diálogo modal a partir de um modelo na `InitModalIndirect`memória, primeiro invoque o construtor sem parâmetros e protegido e, em seguida, ligue .

Depois de construir uma caixa de diálogo modal `DoModal`com um dos métodos acima, ligue .

Para construir uma caixa de diálogo modeless, use a forma protegida do `CDialog` construtor. O construtor está protegido porque você deve derivar sua própria classe caixa de diálogo para implementar uma caixa de diálogo modeless. A construção de uma caixa de diálogo modeless é um processo de duas etapas. Primeira chamada o construtor; em seguida, chame a `Create` função de membro para `CreateIndirect` criar uma caixa de diálogo baseada em recursos ou chamar para criar a caixa de diálogo a partir de um modelo na memória.

## <a name="cdialogcreate"></a><a name="create"></a>CDiálogo::Criar

Chamada `Create` para criar uma caixa de diálogo modeless usando um modelo de caixa de diálogo a partir de um recurso.

```
virtual BOOL Create(
    LPCTSTR lpszTemplateName,
    CWnd* pParentWnd = NULL);

virtual BOOL Create(
    UINT nIDTemplate,
    CWnd* pParentWnd = NULL);
```

### <a name="parameters"></a>Parâmetros

*lpszTemplateName*<br/>
Contém uma seqüência de seqüência de terminadas nula que é o nome de um recurso de modelo de caixa de diálogo.

*Pparentwnd*<br/>
Aponta para o objeto da janela pai (do tipo [CWnd](../../mfc/reference/cwnd-class.md)) ao qual o objeto de diálogo pertence. Se for NULL, a janela pai do objeto de diálogo será definida na janela principal do aplicativo.

*Nidtemplate*<br/>
Contém o número de ID de um recurso de modelo de caixa de diálogo.

### <a name="return-value"></a>Valor retornado

Ambas as formas retornam não zero se a criação e a inicialização da caixa de diálogo forem bem sucedidas; caso contrário, 0.

### <a name="remarks"></a>Comentários

Você pode colocar `Create` a chamada para dentro da construtora ou chamá-la depois que o construtor for invocado.

Duas formas `Create` da função membro são fornecidas para acesso ao recurso de modelo da caixa de diálogo por nome de modelo ou número de ID do modelo (por exemplo, IDD_DIALOG1).

Para qualquer forma, passe um ponteiro para o objeto da janela pai. Se *pParentWnd* for NULL, a caixa de diálogo será criada com a janela pai ou proprietário definida na janela principal do aplicativo.

A `Create` função membro retorna imediatamente após a criação da caixa de diálogo.

Use o estilo WS_VISIBLE no modelo caixa de diálogo se a caixa de diálogo aparecer quando a janela pai for criada. Caso contrário, você `ShowWindow`deve chamar . Para obter mais estilos de caixa de diálogo e sua aplicação, consulte a estrutura [DLGTEMPLATE](/windows/win32/api/winuser/ns-winuser-dlgtemplate) no SDK do Windows e [estilos de janela](../../mfc/reference/styles-used-by-mfc.md#window-styles) na referência *MFC*.

Use `CWnd::DestroyWindow` a função para destruir uma `Create` caixa de diálogo criada pela função.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCControlLadenDialog#62](../../mfc/codesnippet/cpp/cdialog-class_1.cpp)]

## <a name="cdialogcreateindirect"></a><a name="createindirect"></a>cdiálogo::Criar indireta

Chame esta função de membro para criar uma caixa de diálogo modeless a partir de um modelo de caixa de diálogo na memória.

```
virtual BOOL CreateIndirect(
    LPCDLGTEMPLATE lpDialogTemplate,
    CWnd* pParentWnd = NULL,
    void* lpDialogInit = NULL);

virtual BOOL CreateIndirect(
    HGLOBAL hDialogTemplate,
    CWnd* pParentWnd = NULL);
```

### <a name="parameters"></a>Parâmetros

*lpDialogTemplate*<br/>
Aponta para a memória que contém um modelo de caixa de diálogo usado para criar a caixa de diálogo. Este modelo está na forma de uma estrutura [DLGTEMPLATE](/windows/win32/api/winuser/ns-winuser-dlgtemplate) e informações de controle, conforme descrito no SDK do Windows.

*Pparentwnd*<br/>
Aponta para o objeto da janela pai do objeto de diálogo (do tipo [CWnd](../../mfc/reference/cwnd-class.md)). Se for NULL, a janela pai do objeto de diálogo será definida na janela principal do aplicativo.

*lpDialogInit*<br/>
Aponta para um recurso DLGINIT.

*hDiálogoTemplate*<br/>
Contém uma alça para a memória global contendo um modelo de caixa de diálogo. Este modelo é na `DLGTEMPLATE` forma de uma estrutura e dados para cada controle na caixa de diálogo.

### <a name="return-value"></a>Valor retornado

Não zero se a caixa de diálogo foi criada e inicializada com sucesso; caso contrário, 0.

### <a name="remarks"></a>Comentários

A `CreateIndirect` função membro retorna imediatamente após a criação da caixa de diálogo.

Use o estilo WS_VISIBLE no modelo caixa de diálogo se a caixa de diálogo aparecer quando a janela pai for criada. Caso contrário, você `ShowWindow` deve ligar para que ele apareça. Para obter mais informações sobre como você pode especificar outros estilos de caixa de diálogo no modelo, consulte a estrutura [DLGTEMPLATE](/windows/win32/api/winuser/ns-winuser-dlgtemplate) no SDK do Windows.

Use `CWnd::DestroyWindow` a função para destruir uma `CreateIndirect` caixa de diálogo criada pela função.

As caixas de diálogo que contêm controles ActiveX requerem informações adicionais fornecidas em um recurso DLGINIT.

## <a name="cdialogdomodal"></a><a name="domodal"></a>CDialog::DoModal

Ligue para esta função de membro para invocar a caixa de diálogo modal e retornar o resultado da caixa de diálogo quando estiver pronto.

```
virtual INT_PTR DoModal();
```

### <a name="return-value"></a>Valor retornado

Um valor **int** que especifica o valor do parâmetro *nResult* que foi passado para a função [cDialog::EndDialog](#enddialog) member, que é usada para fechar a caixa de diálogo. O valor de retorno é -1 se a função não puder criar a caixa de diálogo ou IDABORT se ocorreu algum outro erro, nesse caso a janela de saída conterá informações de erro do [GetLastError](/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

### <a name="remarks"></a>Comentários

Esta função de membro lida com toda a interação com o usuário enquanto a caixa de diálogo estiver ativa. É isso que torna a caixa de diálogo modal; ou seja, o usuário não pode interagir com outras janelas até que a caixa de diálogo esteja fechada.

Se o usuário clicar em um dos botões na caixa de diálogo, como OK ou Cancel, uma função de membro do manipulador de mensagens, como [OnOK](#onok) ou [OnCancel,](#oncancel)será chamada para tentar fechar a caixa de diálogo. A `OnOK` função de membro padrão validará e atualizará os dados da caixa de `OnCancel` diálogo e fechará a caixa de diálogo com iDOK de resultado, e a função de membro padrão fechará a caixa de diálogo com o IDCANCEL de resultado sem validar ou atualizar os dados da caixa de diálogo. Você pode substituir essas funções de manipulador de mensagens para alterar seu comportamento.

> [!NOTE]
> `PreTranslateMessage`agora é chamado para o processamento de mensagem da caixa de diálogo modal.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCControlLadenDialog#63](../../mfc/codesnippet/cpp/cdialog-class_2.cpp)]

## <a name="cdialogenddialog"></a><a name="enddialog"></a>cdiálogo::EndDialog

Chame esta função de membro para encerrar uma caixa de diálogo modal.

```cpp
void EndDialog(int nResult);
```

### <a name="parameters"></a>Parâmetros

*Nresult*<br/>
Contém o valor a ser devolvido da caixa `DoModal`de diálogo para o chamador de .

### <a name="remarks"></a>Comentários

Esta função de membro retorna *nResult* como o valor de retorno de `DoModal`. Você deve `EndDialog` usar a função para concluir o processamento sempre que uma caixa de diálogo modal for criada.

Você pode `EndDialog` ligar a qualquer momento, mesmo no [OnInitDialog,](#oninitdialog)nesse caso, você deve fechar a caixa de diálogo antes de ser exibida ou antes que o foco de entrada seja definido.

`EndDialog`não fecha a caixa de diálogo imediatamente. Em vez disso, ele define um sinalizador que direciona a caixa de diálogo para fechar assim que o manipulador de mensagens atual retornar.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCControlLadenDialog#64](../../mfc/codesnippet/cpp/cdialog-class_3.cpp)]

[!code-cpp[NVC_MFCControlLadenDialog#65](../../mfc/codesnippet/cpp/cdialog-class_4.cpp)]

## <a name="cdialoggetdefid"></a><a name="getdefid"></a>Diálogo::GetDefID

Ligue `GetDefID` para a função membro para obter o ID do controle de botão padrão para uma caixa de diálogo.

```
DWORD GetDefID() const;
```

### <a name="return-value"></a>Valor retornado

Um valor de 32 bits ( `DWORD`). Se o botão padrão tiver um valor de ID, a palavra de alta ordem contém DC_HASDEFID e a palavra de baixa ordem contém o valor de ID. Se o botão padrão não tiver um valor de ID, o valor de retorno será 0.

### <a name="remarks"></a>Comentários

Este é geralmente um botão OK.

## <a name="cdialoggotodlgctrl"></a><a name="gotodlgctrl"></a>CDialog::GotoDlgCtrl

Move o foco para o controle especificado na caixa de diálogo.

```cpp
void GotoDlgCtrl(CWnd* pWndCtrl);
```

### <a name="parameters"></a>Parâmetros

*pWndCtrl*<br/>
Identifica a janela (controle) que deve receber o foco.

### <a name="remarks"></a>Comentários

Para obter um ponteiro para o controle (janela filho) para passar `CWnd::GetDlgItem` como *pWndCtrl*, ligue para a função membro, que retorna um ponteiro para um objeto [CWnd.](../../mfc/reference/cwnd-class.md)

### <a name="example"></a>Exemplo

  Veja o exemplo [de CWnd::GetDlgItem](../../mfc/reference/cwnd-class.md#getdlgitem).

## <a name="cdialoginitmodalindirect"></a><a name="initmodalindirect"></a>CDialog::InitModalIndirect

Chame esta função de membro para inicializar um objeto de diálogo modal usando um modelo de caixa de diálogo que você constrói na memória.

```
BOOL InitModalIndirect(
    LPCDLGTEMPLATE lpDialogTemplate,
    CWnd* pParentWnd = NULL,
    void* lpDialogInit = NULL);

    BOOL InitModalIndirect(
    HGLOBAL hDialogTemplate,
    CWnd* pParentWnd = NULL);
```

### <a name="parameters"></a>Parâmetros

*lpDialogTemplate*<br/>
Aponta para a memória que contém um modelo de caixa de diálogo usado para criar a caixa de diálogo. Este modelo está na forma de uma estrutura [DLGTEMPLATE](/windows/win32/api/winuser/ns-winuser-dlgtemplate) e informações de controle, conforme descrito no SDK do Windows.

*hDiálogoTemplate*<br/>
Contém uma alça para a memória global contendo um modelo de caixa de diálogo. Este modelo é na `DLGTEMPLATE` forma de uma estrutura e dados para cada controle na caixa de diálogo.

*Pparentwnd*<br/>
Aponta para o objeto da janela pai ou proprietário (do tipo [CWnd)](../../mfc/reference/cwnd-class.md)ao qual o objeto de diálogo pertence. Se for NULL, a janela pai do objeto de diálogo será definida na janela principal do aplicativo.

*lpDialogInit*<br/>
Aponta para um recurso DLGINIT.

### <a name="return-value"></a>Valor retornado

Não zero se o objeto de diálogo foi criado e inicializado com sucesso; caso contrário, 0.

### <a name="remarks"></a>Comentários

Para criar indiretamente uma caixa de diálogo modal, primeiro aloque um bloco global de memória e preencha-a com o modelo da caixa de diálogo. Em seguida, `CDialog` chame o construtor vazio para construir o objeto caixa de diálogo. Em seguida, ligue `InitModalIndirect` para armazenar sua alça no modelo de caixa de diálogo na memória. A caixa de diálogo do Windows é criada e exibida posteriormente, quando a função [membro DoModal](#domodal) é chamada.

As caixas de diálogo que contêm controles ActiveX requerem informações adicionais fornecidas em um recurso DLGINIT.

## <a name="cdialogmapdialogrect"></a><a name="mapdialogrect"></a>CDiálogo::MapDialogRect

Chamada para converter as unidades da caixa de diálogo de um retângulo para unidades de tela.

```cpp
void MapDialogRect(LPRECT lpRect) const;
```

### <a name="parameters"></a>Parâmetros

*Lprect*<br/>
Aponta para uma estrutura [RECT](/windows/win32/api/windef/ns-windef-rect) ou objeto [CRect](../../atl-mfc-shared/reference/crect-class.md) que contém as coordenadas da caixa de diálogo a ser convertida.

### <a name="remarks"></a>Comentários

As unidades de caixa de diálogo são indicadas em termos da unidade base da caixa de diálogo atual derivada da largura e altura médiados caracteres na fonte usada para texto da caixa de diálogo. Uma unidade horizontal é um quarto da unidade de largura base da caixa de diálogo, e uma unidade vertical é um oitavo da unidade de altura da base da caixa de diálogo.

A `GetDialogBaseUnits` função Windows retorna informações de tamanho para a fonte do sistema, mas você pode especificar uma fonte diferente para cada caixa de diálogo se você usar o estilo DS_SETFONT no arquivo de definição de recurso. A `MapDialogRect` função Windows usa a fonte apropriada para esta caixa de diálogo.

A `MapDialogRect` função membro substitui as unidades da caixa de diálogo em *lpRect* por unidades de tela (pixels) para que o retângulo possa ser usado para criar uma caixa de diálogo ou posicionar um controle dentro de uma caixa.

## <a name="cdialognextdlgctrl"></a><a name="nextdlgctrl"></a>CDialog::NextDlgCtrl

Move o foco para o próximo controle na caixa de diálogo.

```cpp
void NextDlgCtrl() const;
```

### <a name="remarks"></a>Comentários

Se o foco estiver no último controle na caixa de diálogo, ele se move para o primeiro controle.

## <a name="cdialogoncancel"></a><a name="oncancel"></a>cdialog::Oncancel

A estrutura chama esse método quando o usuário **clica em Cancelar** ou pressionar a tecla ESC em uma caixa de diálogo modal ou modeless.

```
virtual void OnCancel();
```

### <a name="remarks"></a>Comentários

Anular esse método para executar ações (como restaurar dados antigos) quando um usuário fecha a caixa de diálogo clicando em **Cancelar** ou apertando a tecla ESC. O padrão fecha uma caixa de diálogo modal ligando para [EndDialog](#enddialog) e fazendo com que [o DoModal](#domodal) retorne o IDCANCEL.

Se você implementar o botão **Cancelar** em uma caixa de `OnCancel` diálogo modeless, você deve substituir o método e chamar [DestroyWindow](../../mfc/reference/cwnd-class.md#destroywindow) dentro dele. Não chame o método de classe `EndDialog`base, porque ele chama , o que tornará a caixa de diálogo invisível, mas não destruí-la.

> [!NOTE]
> Não é possível substituir este `CFileDialog` método quando usar um objeto em um programa compilado no Windows XP. Para obter `CFileDialog`mais informações sobre, consulte [CFileDialog Class](../../mfc/reference/cfiledialog-class.md).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCControlLadenDialog#66](../../mfc/codesnippet/cpp/cdialog-class_5.cpp)]

## <a name="cdialogoninitdialog"></a><a name="oninitdialog"></a>CDialog::OnInitDialog

Este método é chamado `WM_INITDIALOG` em resposta à mensagem.

```
virtual BOOL OnInitDialog();
```

### <a name="return-value"></a>Valor retornado

Especifica se o aplicativo definiu o foco de entrada para um dos controles na caixa de diálogo. Se `OnInitDialog` retornar não zero, o Windows definirá o foco de entrada para o local padrão, o primeiro controle na caixa de diálogo. O aplicativo só pode retornar 0 se tiver explicitamente definido o foco de entrada para um dos controles na caixa de diálogo.

### <a name="remarks"></a>Comentários

O Windows `WM_INITDIALOG` envia a mensagem para a caixa de diálogo durante as chamadas [Criar,](#create) [CriarInio](#createindirect)ou [DoModal,](#domodal) que ocorrem imediatamente antes da caixa de diálogo ser exibida.

Anular este método se você quiser executar um processamento especial quando a caixa de diálogo é inicializada. Na versão substituída, primeiro chame a `OnInitDialog` classe base, mas ignore seu valor de retorno. Você normalmente `TRUE` retornará do seu método substituído.

O Windows `OnInitDialog` chama a função usando o procedimento padrão de caixa de diálogo global comum a todas as caixas de diálogo da Biblioteca de Classe da Microsoft Foundation. Ele não chama essa função através do seu mapa de mensagem e, portanto, você não precisa de uma entrada de mapa de mensagem para este método.

> [!NOTE]
> Não é possível substituir esse `CFileDialog` método quando usa um objeto em um programa compilado no Windows Vista ou em sistemas operacionais posteriores. Para obter mais `CFileDialog` informações sobre alterações no Windows Vista e posteriormente, consulte [CFileDialog Class](../../mfc/reference/cfiledialog-class.md).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCControlLadenDialog#67](../../mfc/codesnippet/cpp/cdialog-class_6.cpp)]

## <a name="cdialogonok"></a><a name="onok"></a>cdialog::OnOK

Chamado quando o usuário clica no botão **OK** (o botão com um ID de IDOK).

```
virtual void OnOK();
```

### <a name="remarks"></a>Comentários

Anular este método para executar ações quando o botão **OK** estiver ativado. Se a caixa de diálogo incluir validação e troca automática de dados, a implementação padrão deste método validará os dados da caixa de diálogo e atualizará as variáveis apropriadas em seu aplicativo.

Se você implementar o botão **OK** em uma caixa de `OnOK` diálogo modeless, você deve substituir o método e chamar [DestroyWindow](../../mfc/reference/cwnd-class.md#destroywindow) dentro dele. Não chame o método de classe base, porque ele chama [EndDialog,](#enddialog) que torna a caixa de diálogo invisível, mas não a destrói.

> [!NOTE]
> Não é possível substituir este `CFileDialog` método quando usar um objeto em um programa compilado no Windows XP. Para obter `CFileDialog`mais informações sobre, consulte [CFileDialog Class](../../mfc/reference/cfiledialog-class.md).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCControlLadenDialog#68](../../mfc/codesnippet/cpp/cdialog-class_7.cpp)]

## <a name="cdialogonsetfont"></a><a name="onsetfont"></a>diálogo::Fonte de início

Especifica a fonte que um controle de caixa de diálogo usará ao desenhar texto.

```
Virtual void OnSetFont(CFont* pFont);
```

### <a name="parameters"></a>Parâmetros

*fonte p*<br/>
[em] Especifica um ponteiro para a fonte que será usada como fonte padrão para todos os controles nesta caixa de diálogo.

### <a name="remarks"></a>Comentários

A caixa de diálogo usará a fonte especificada como padrão para todos os seus controles.

O editor de diálogo normalmente define a fonte caixa de diálogo como parte do recurso de modelo caixa de diálogo.

> [!NOTE]
> Não é possível substituir esse `CFileDialog` método quando usa um objeto em um programa compilado no Windows Vista ou em sistemas operacionais posteriores. Para obter mais `CFileDialog` informações sobre alterações no Windows Vista e posteriormente, consulte [CFileDialog Class](../../mfc/reference/cfiledialog-class.md).

## <a name="cdialogprevdlgctrl"></a><a name="prevdlgctrl"></a>CDialog::PrevDlgCtrl

Define o foco para o controle anterior na caixa de diálogo.

```cpp
void PrevDlgCtrl() const;
```

### <a name="remarks"></a>Comentários

Se o foco estiver no primeiro controle na caixa de diálogo, ele se move para o último controle na caixa.

## <a name="cdialogsetdefid"></a><a name="setdefid"></a>CDialog::SetDefID

Altera o controle de botão padrão para uma caixa de diálogo.

```cpp
void SetDefID(UINT nID);
```

### <a name="parameters"></a>Parâmetros

*nID*<br/>
Especifica o ID do controle do botão que se tornará o padrão.

## <a name="cdialogsethelpid"></a><a name="sethelpid"></a>diálogo::sethelpid

Define um ID de ajuda sensível ao contexto para a caixa de diálogo.

```cpp
void SetHelpID(UINT nIDR);
```

### <a name="parameters"></a>Parâmetros

*nIDR*<br/>
Especifica o ID de ajuda sensível ao contexto.

## <a name="see-also"></a>Confira também

[Amostra de MFC DLGCBR32](../../overview/visual-cpp-samples.md)<br/>
[Amostra de MFC DLGTEMPL](../../overview/visual-cpp-samples.md)<br/>
[Classe CWnd](../../mfc/reference/cwnd-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)
