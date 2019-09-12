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
ms.openlocfilehash: b07190c70fb11950b25aff45fb10e850c0e81b24
ms.sourcegitcommit: 3caf5261b3ea80d9cf14038c116ba981d655cd13
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/11/2019
ms.locfileid: "70907617"
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
|[CDialog:: CDialog](#cdialog)|Constrói um objeto `CDialog`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CDialog:: criar](#create)|Inicializa o objeto `CDialog`. Cria uma caixa de diálogo sem janela restrita e a anexa ao `CDialog` objeto.|
|[CDialog:: indireto](#createindirect)|Cria uma caixa de diálogo sem janela restrita a partir de um modelo de caixa de diálogo na memória (não baseado em recurso).|
|[CDialog::D oModal](#domodal)|Chama uma caixa de diálogo modal e retorna quando concluído.|
|[CDialog:: EndDialog](#enddialog)|Fecha uma caixa de diálogo modal.|
|[CDialog::GetDefID](#getdefid)|Obtém a ID do controle de pressão padrão para uma caixa de diálogo.|
|[CDialog::GotoDlgCtrl](#gotodlgctrl)|Move o foco para um controle de caixa de diálogo especificado na caixa de diálogo.|
|[CDialog::InitModalIndirect](#initmodalindirect)|Cria uma caixa de diálogo modal a partir de um modelo de caixa de diálogo na memória (não baseado em recurso). Os parâmetros são armazenados até que a `DoModal` função seja chamada.|
|[CDialog::MapDialogRect](#mapdialogrect)|Converte as unidades de caixa de diálogo de um retângulo em unidades de tela.|
|[CDialog::NextDlgCtrl](#nextdlgctrl)|Move o foco para o próximo controle da caixa de diálogo na caixa de diálogo.|
|[CDialog::OnInitDialog](#oninitdialog)|Substituir para aumentar a inicialização da caixa de diálogo.|
|[CDialog::OnSetFont](#onsetfont)|Substituir para especificar a fonte que um controle de caixa de diálogo deve usar ao desenhar texto.|
|[CDialog::P revDlgCtrl](#prevdlgctrl)|Move o foco para o controle da caixa de diálogo anterior na caixa de diálogo.|
|[CDialog::SetDefID](#setdefid)|Altera o controle de pressão padrão para uma caixa de diálogo para um botão de pressão especificado.|
|[CDialog:: sethelpid](#sethelpid)|Define uma ID de ajuda sensível ao contexto para a caixa de diálogo.|

### <a name="protected-methods"></a>Métodos Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CDialog:: OnCancel](#oncancel)|Substitua para executar o botão de cancelamento ou a ação de tecla ESC. O padrão fecha a caixa de diálogo `DoModal` e retorna IDCANCEL.|
|[CDialog:: OnOK](#onok)|Substitua para executar a ação do botão OK em uma caixa de diálogo modal. O padrão fecha a caixa de diálogo `DoModal` e retorna IDOK.|

## <a name="remarks"></a>Comentários

As caixas de diálogo são de dois tipos: modal e sem janela restrita. Uma caixa de diálogo modal deve ser fechada pelo usuário antes de o aplicativo continuar. Uma caixa de diálogo sem janela restrita permite que o usuário exiba a caixa de diálogo e retorne a outra tarefa sem cancelar ou remover a caixa de diálogo.

Um `CDialog` objeto é uma combinação de um modelo de caixa de `CDialog`diálogo e de uma classe derivada. Use o editor de caixa de diálogo para criar o modelo de caixa de diálogo e armazená-lo em um recurso e, em seguida, `CDialog`use o assistente para adicionar classe para criar uma classe derivada de.

Uma caixa de diálogo, como qualquer outra janela, recebe mensagens do Windows. Em uma caixa de diálogo, você está particularmente interessado em lidar com mensagens de notificação dos controles da caixa de diálogo, já que é assim que o usuário interage com sua caixa de diálogo. Use o [Assistente de classe](mfc-class-wizard.md) para selecionar as mensagens que você deseja manipular e elas adicionarão as entradas de mapa de mensagem e as funções de membro do manipulador de mensagens apropriadas à classe para você. Você só precisa escrever código específico do aplicativo nas funções de membro do manipulador.

Se preferir, você sempre poderá gravar entradas de mapeamento de mensagem e funções de membro manualmente.

No, exceto na caixa de diálogo mais trivial, você adiciona variáveis de membro à sua classe de caixa de diálogo derivada para armazenar dados inseridos nos controles da caixa de diálogo pelo usuário ou para exibir dados para o usuário. Você pode usar o assistente para Adicionar variável para criar variáveis de membro e associá-las a controles. Ao mesmo tempo, você escolhe um tipo de variável e um intervalo de valores permitidos para cada variável. O assistente de código adiciona as variáveis de membro à sua classe de caixa de diálogo derivada.

Um mapa de dados é gerado para lidar automaticamente com a troca de dados entre as variáveis de membro e os controles da caixa de diálogo. O mapa de dados fornece funções que inicializam os controles na caixa de diálogo com os valores apropriados, recuperam os dados e validam os dados.

Para criar uma caixa de diálogo modal, construa um objeto na pilha usando o construtor para a classe de caixa de diálogo derivada `DoModal` e, em seguida, chame para criar a janela de caixa de diálogo e seus controles. Se você quiser criar uma caixa de diálogo sem janela restrita `Create` , chame no construtor da sua classe DIALOG.

Você também pode criar um modelo na memória usando uma estrutura de dados [DLGTEMPLATE](/windows/win32/api/winuser/ns-winuser-dlgtemplate) , conforme descrito na SDK do Windows. Depois de construir um `CDialog` objeto, chame [indireto](#createindirect) para criar uma caixa de diálogo sem janela restrita ou chame [InitModalIndirect](#initmodalindirect) e [DoModal](#domodal) para criar uma caixa de diálogo modal.

O mapa de dados de validação e do Exchange é escrito em `CWnd::DoDataExchange` uma substituição de que é adicionada à sua nova classe de caixa de diálogo. Consulte a função membro [DoDataExchange](../../mfc/reference/cwnd-class.md#dodataexchange) no `CWnd` para obter mais informações sobre a funcionalidade de validação e do Exchange.

O programador e a chamada `DoDataExchange` de estrutura indiretamente por meio de uma chamada para [CWnd:: UpdateData](../../mfc/reference/cwnd-class.md#updatedata).

A estrutura chama `UpdateData` quando o usuário clica no botão OK para fechar uma caixa de diálogo modal. (Os dados não serão recuperados se o botão Cancelar for clicado.) A implementação padrão de [OnInitDialog](#oninitdialog) também chama `UpdateData` para definir os valores iniciais dos controles. Normalmente, você `OnInitDialog` substitui para inicializar outros controles. `OnInitDialog`é chamado depois que todos os controles de diálogo são criados e logo antes da caixa de diálogo ser exibida.

Você pode chamar `CWnd::UpdateData` a qualquer momento durante a execução de uma caixa de diálogo modal ou sem janela restrita.

Se você desenvolver uma caixa de diálogo manualmente, adicionará as variáveis de membro necessárias à classe de caixa de diálogo derivada por conta própria e adicionará funções de membro para definir ou obter esses valores.

Uma caixa de diálogo modal é fechada automaticamente quando o usuário pressiona os botões OK ou cancelar ou quando seu código chama `EndDialog` a função de membro.

Quando você implementa uma caixa de diálogo sem janela restrita, o `OnCancel` sempre substitui a função `DestroyWindow` de membro e a chama de dentro dela. Não chame a classe `CDialog::OnCancel`base, porque ela chama `EndDialog`, o que fará com que a caixa de diálogo fique invisível, mas não a destruirá. Você também deve substituir `PostNcDestroy` as caixas de diálogo sem janela restrita para excluir **isso**, uma vez que as caixas de diálogo sem janela restrita geralmente são alocadas com o **novo**. As caixas de diálogo modais geralmente são construídas no quadro e não `PostNcDestroy` precisam de limpeza.

Para obter mais informações `CDialog`sobre o, consulte [caixas de diálogo](../../mfc/dialog-boxes.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

`CDialog`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Afxwin. h

##  <a name="cdialog"></a>CDialog:: CDialog

Para construir uma caixa de diálogo modal baseada em recursos, chame uma forma pública do construtor.

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
Contém uma cadeia de caracteres terminada em nulo que é o nome de um recurso de modelo de caixa de diálogo.

*nIDTemplate*<br/>
Contém o número de ID de um recurso de modelo de caixa de diálogo.

*pParentWnd*<br/>
Aponta para o objeto de janela pai ou proprietário (do tipo [CWnd](../../mfc/reference/cwnd-class.md)) ao qual o objeto de caixa de diálogo pertence. Se for NULL, a janela pai do objeto de caixa de diálogo será definida como a janela principal do aplicativo.

### <a name="remarks"></a>Comentários

Uma forma do construtor fornece acesso ao recurso de caixa de diálogo pelo nome do modelo. O outro construtor fornece acesso por número de ID de modelo, geralmente com um prefixo **IDD_** (por exemplo, IDD_DIALOG1).

Para construir uma caixa de diálogo modal de um modelo na memória, primeiro invoque o construtor protegido sem parâmetros e, em `InitModalIndirect`seguida, chame.

Depois de construir uma caixa de diálogo modal com um dos métodos acima, chame `DoModal`.

Para construir uma caixa de diálogo sem janela restrita, use o formulário protegido `CDialog` do construtor. O construtor é protegido porque você deve derivar sua própria classe de caixa de diálogo para implementar uma caixa de diálogo sem janela restrita. A construção de uma caixa de diálogo sem janela restrita é um processo de duas etapas. Primeiro, chame o Construtor; em seguida, `Create` chame a função de membro para criar uma caixa de diálogo baseada em `CreateIndirect` recursos ou chame para criar a caixa de diálogo de um modelo na memória.

##  <a name="create"></a>CDialog:: criar

Chame `Create` para criar uma caixa de diálogo sem janela restrita usando um modelo de caixa de diálogo de um recurso.

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
Contém uma cadeia de caracteres terminada em nulo que é o nome de um recurso de modelo de caixa de diálogo.

*pParentWnd*<br/>
Aponta para o objeto de janela pai (do tipo [CWnd](../../mfc/reference/cwnd-class.md)) ao qual o objeto de caixa de diálogo pertence. Se for NULL, a janela pai do objeto de caixa de diálogo será definida como a janela principal do aplicativo.

*nIDTemplate*<br/>
Contém o número de ID de um recurso de modelo de caixa de diálogo.

### <a name="return-value"></a>Valor de retorno

Os dois formulários retornam zero se a criação e a inicialização da caixa de diálogo foram bem-sucedidas; caso contrário, 0.

### <a name="remarks"></a>Comentários

Você pode colocar a chamada para `Create` dentro do construtor ou chamá-la depois que o Construtor for invocado.

Duas formas da `Create` função membro são fornecidas para acesso ao recurso de modelo de caixa de diálogo pelo nome do modelo ou pelo número de ID do modelo (por exemplo, IDD_DIALOG1).

Para qualquer um dos formulários, passe um ponteiro para o objeto da janela pai. Se *pParentWnd* for nulo, a caixa de diálogo será criada com sua janela pai ou proprietário definida como a janela principal do aplicativo.

A `Create` função de membro retorna imediatamente após a criação da caixa de diálogo.

Use o estilo WS_VISIBLE no modelo da caixa de diálogo se a caixa de diálogo for exibida quando a janela pai for criada. Caso contrário, você deve `ShowWindow`chamar. Para obter mais estilos de caixa de diálogo e seus aplicativos, consulte a estrutura [DLGTEMPLATE](/windows/win32/api/winuser/ns-winuser-dlgtemplate) nos estilos de SDK do Windows e de [janela](../../mfc/reference/styles-used-by-mfc.md#window-styles) na *referência do MFC*.

Use a `CWnd::DestroyWindow` função para destruir uma caixa de diálogo criada `Create` pela função.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCControlLadenDialog#62](../../mfc/codesnippet/cpp/cdialog-class_1.cpp)]

##  <a name="createindirect"></a>CDialog:: indireto

Chame essa função de membro para criar uma caixa de diálogo sem janela restrita a partir de um modelo de caixa de diálogo na memória.

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
Aponta para a memória que contém um modelo de caixa de diálogo usado para criar a caixa de diálogo. Esse modelo está na forma de uma estrutura [DLGTEMPLATE](/windows/win32/api/winuser/ns-winuser-dlgtemplate) e informações de controle, conforme descrito na SDK do Windows.

*pParentWnd*<br/>
Aponta para o objeto de janela pai do objeto de caixa de diálogo (do tipo [CWnd](../../mfc/reference/cwnd-class.md)). Se for NULL, a janela pai do objeto de caixa de diálogo será definida como a janela principal do aplicativo.

*lpDialogInit*<br/>
Aponta para um recurso DLGINIT.

*hDialogTemplate*<br/>
Contém um identificador para a memória global que contém um modelo de caixa de diálogo. Esse modelo está na forma de uma `DLGTEMPLATE` estrutura e dados para cada controle na caixa de diálogo.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a caixa de diálogo foi criada e inicializada com êxito; caso contrário, 0.

### <a name="remarks"></a>Comentários

A `CreateIndirect` função de membro retorna imediatamente após a criação da caixa de diálogo.

Use o estilo WS_VISIBLE no modelo da caixa de diálogo se a caixa de diálogo for exibida quando a janela pai for criada. Caso contrário, você deve `ShowWindow` chamar para fazer com que ela seja exibida. Para obter mais informações sobre como você pode especificar outros estilos de caixa de diálogo no modelo, consulte a estrutura [DLGTEMPLATE](/windows/win32/api/winuser/ns-winuser-dlgtemplate) no SDK do Windows.

Use a `CWnd::DestroyWindow` função para destruir uma caixa de diálogo criada `CreateIndirect` pela função.

Caixas de diálogo que contêm controles ActiveX exigem informações adicionais fornecidas em um recurso DLGINIT.

##  <a name="domodal"></a>CDialog::D oModal

Chame essa função de membro para invocar a caixa de diálogo modal e retornar o resultado da caixa de diálogo quando terminar.

```
virtual INT_PTR DoModal();
```

### <a name="return-value"></a>Valor de retorno

Um valor **int** que especifica o valor do parâmetro *nresultado* que foi passado para a função membro [CDialog:: EndDialog](#enddialog) , que é usada para fechar a caixa de diálogo. O valor de retorno será-1 se a função não pôde criar a caixa de diálogo, ou IDABORT se algum outro erro ocorreu; nesse caso, a janela de saída conterá informações de erro de [GetLastError](/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

### <a name="remarks"></a>Comentários

Essa função de membro manipula toda a interação com o usuário enquanto a caixa de diálogo está ativa. É isso que torna a caixa de diálogo modal; ou seja, o usuário não pode interagir com outras janelas até que a caixa de diálogo seja fechada.

Se o usuário clicar em um dos pressionamentos na caixa de diálogo, como OK ou cancelar, uma função de membro do manipulador de mensagens, como [OnOK](#onok) ou [OnCancel](#oncancel), será chamada para tentar fechar a caixa de diálogo. A função `OnOK` membro padrão validará e atualizará os dados da caixa de diálogo e fechará a caixa de diálogo com resultado IDOK `OnCancel` , e a função membro padrão fechará a caixa de diálogo com resultado IDCANCEL sem validar ou atualizar o dados da caixa de diálogo. Você pode substituir essas funções de manipulador de mensagens para alterar seu comportamento.

> [!NOTE]
> `PreTranslateMessage`Agora é chamado para o processamento de mensagens da caixa de diálogo modal.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCControlLadenDialog#63](../../mfc/codesnippet/cpp/cdialog-class_2.cpp)]

##  <a name="enddialog"></a>CDialog:: EndDialog

Chame essa função de membro para encerrar uma caixa de diálogo modal.

```
void EndDialog(int nResult);
```

### <a name="parameters"></a>Parâmetros

*nResult*<br/>
Contém o valor a ser retornado da caixa de diálogo para o chamador de `DoModal`.

### <a name="remarks"></a>Comentários

Essa função de membro retorna *nresultado* como o valor de `DoModal`retorno de. Você deve usar a `EndDialog` função para concluir o processamento sempre que uma caixa de diálogo modal for criada.

Você pode chamar `EndDialog` a qualquer momento, mesmo no [OnInitDialog](#oninitdialog), caso em que você deve fechar a caixa de diálogo antes que ela seja exibida ou antes de o foco de entrada ser definido.

`EndDialog`Não fecha a caixa de diálogo imediatamente. Em vez disso, ele define um sinalizador que direciona a caixa de diálogo para fechar assim que o manipulador de mensagens atual retorna.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCControlLadenDialog#64](../../mfc/codesnippet/cpp/cdialog-class_3.cpp)]

[!code-cpp[NVC_MFCControlLadenDialog#65](../../mfc/codesnippet/cpp/cdialog-class_4.cpp)]

##  <a name="getdefid"></a>  CDialog::GetDefID

Chame a `GetDefID` função de membro para obter a ID do controle de pressão padrão para uma caixa de diálogo.

```
DWORD GetDefID() const;
```

### <a name="return-value"></a>Valor de retorno

Um valor de 32 bits ( `DWORD`). Se o botão de pressão padrão tiver um valor de ID, a palavra de ordem superior conterá DC_HASDEFID e a palavra de ordem inferior conterá o valor de ID. Se o botão de pressão padrão não tiver um valor de ID, o valor de retorno será 0.

### <a name="remarks"></a>Comentários

Esse é geralmente um botão OK.

##  <a name="gotodlgctrl"></a>CDialog:: GotoDlgCtrl

Move o foco para o controle especificado na caixa de diálogo.

```
void GotoDlgCtrl(CWnd* pWndCtrl);
```

### <a name="parameters"></a>Parâmetros

*pWndCtrl*<br/>
Identifica a janela (controle) que deve receber o foco.

### <a name="remarks"></a>Comentários

Para obter um ponteiro para o controle (janela filho) a ser passado como *pWndCtrl*, chame `CWnd::GetDlgItem` a função member, que retorna um ponteiro para um objeto [CWnd](../../mfc/reference/cwnd-class.md) .

### <a name="example"></a>Exemplo

  Consulte o exemplo de [CWnd:: GetDlgItem](../../mfc/reference/cwnd-class.md#getdlgitem).

##  <a name="initmodalindirect"></a>CDialog:: InitModalIndirect

Chame essa função de membro para inicializar um objeto de diálogo modal usando um modelo de caixa de diálogo que você constrói na memória.

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
Aponta para a memória que contém um modelo de caixa de diálogo usado para criar a caixa de diálogo. Esse modelo está na forma de uma estrutura [DLGTEMPLATE](/windows/win32/api/winuser/ns-winuser-dlgtemplate) e informações de controle, conforme descrito na SDK do Windows.

*hDialogTemplate*<br/>
Contém um identificador para a memória global que contém um modelo de caixa de diálogo. Esse modelo está na forma de uma `DLGTEMPLATE` estrutura e dados para cada controle na caixa de diálogo.

*pParentWnd*<br/>
Aponta para o objeto de janela pai ou proprietário (do tipo [CWnd](../../mfc/reference/cwnd-class.md)) ao qual o objeto de caixa de diálogo pertence. Se for NULL, a janela pai do objeto de caixa de diálogo será definida como a janela principal do aplicativo.

*lpDialogInit*<br/>
Aponta para um recurso DLGINIT.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o objeto da caixa de diálogo foi criado e inicializado com êxito; caso contrário, 0.

### <a name="remarks"></a>Comentários

Para criar uma caixa de diálogo modal indiretamente, primeiro aloque um bloco de memória global e preencha-o com o modelo de caixa de diálogo. Em seguida, chame `CDialog` o construtor vazio para construir o objeto da caixa de diálogo. Em seguida, `InitModalIndirect` chame para armazenar seu identificador para o modelo da caixa de diálogo na memória. A caixa de diálogo do Windows é criada e exibida mais tarde, quando a função de membro [DoModal](#domodal) é chamada.

Caixas de diálogo que contêm controles ActiveX exigem informações adicionais fornecidas em um recurso DLGINIT.

##  <a name="mapdialogrect"></a>CDialog:: MapDialogRect

Chame para converter as unidades da caixa de diálogo de um retângulo em unidades de tela.

```
void MapDialogRect(LPRECT lpRect) const;
```

### <a name="parameters"></a>Parâmetros

*lpRect*<br/>
Aponta para uma estrutura [Rect](/windows/win32/api/windef/ns-windef-rect) ou um objeto [CRect](../../atl-mfc-shared/reference/crect-class.md) que contém as coordenadas da caixa de diálogo a serem convertidas.

### <a name="remarks"></a>Comentários

As unidades da caixa de diálogo são indicadas em termos da unidade base da caixa de diálogo atual derivada da largura média e da altura dos caracteres na fonte usada para o texto da caixa de diálogo. Uma unidade horizontal é uma quarta da unidade de largura base da caixa de diálogo e uma unidade vertical é um oitavo da unidade de altura base da caixa de diálogo.

A `GetDialogBaseUnits` função do Windows retorna informações de tamanho para a fonte do sistema, mas você pode especificar uma fonte diferente para cada caixa de diálogo se usar o estilo DS_SETFONT no arquivo de definição de recurso. A `MapDialogRect` função do Windows usa a fonte apropriada para essa caixa de diálogo.

A `MapDialogRect` função membro substitui as unidades da caixa de diálogo em *lpRect* por unidades de tela (pixels) para que o retângulo possa ser usado para criar uma caixa de diálogo ou posicionar um controle dentro de uma caixa.

##  <a name="nextdlgctrl"></a>  CDialog::NextDlgCtrl

Move o foco para o próximo controle na caixa de diálogo.

```
void NextDlgCtrl() const;
```

### <a name="remarks"></a>Comentários

Se o foco estiver no último controle da caixa de diálogo, ele passará para o primeiro controle.

##  <a name="oncancel"></a>CDialog:: OnCancel

A estrutura chama esse método quando o usuário clica em **Cancelar** ou pressiona a tecla ESC em uma caixa de diálogo modal ou sem janela restrita.

```
virtual void OnCancel();
```

### <a name="remarks"></a>Comentários

Substitua esse método para executar ações (como restaurar dados antigos) quando um usuário fechar a caixa de diálogo clicando em **Cancelar** ou pressionando a tecla ESC. O padrão fecha uma caixa de diálogo modal chamando [EndDialog](#enddialog) e fazendo com que [DOMODAL](#domodal) retorne IDCANCEL.

Se você implementar o botão **Cancelar** em uma caixa de diálogo sem janela restrita, deverá substituir `OnCancel` o método e chamar [DestroyWindow](../../mfc/reference/cwnd-class.md#destroywindow) dentro dele. Não chame o método de classe base, pois ele chama `EndDialog`, o que tornará a caixa de diálogo invisível, mas não a destruirá.

> [!NOTE]
>  Não é possível substituir esse método quando você usa `CFileDialog` um objeto em um programa que é compilado no Windows XP. Para obter mais informações `CFileDialog`sobre, consulte [classe CFileDialog](../../mfc/reference/cfiledialog-class.md).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCControlLadenDialog#66](../../mfc/codesnippet/cpp/cdialog-class_5.cpp)]

##  <a name="oninitdialog"></a>CDialog:: OnInitDialog

Esse método é chamado em resposta à `WM_INITDIALOG` mensagem.

```
virtual BOOL OnInitDialog();
```

### <a name="return-value"></a>Valor de retorno

Especifica se o aplicativo definiu o foco de entrada para um dos controles na caixa de diálogo. Se `OnInitDialog` retornar zero, o Windows definirá o foco de entrada para o local padrão, o primeiro controle na caixa de diálogo. O aplicativo só poderá retornar 0 se tiver definido explicitamente o foco de entrada para um dos controles na caixa de diálogo.

### <a name="remarks"></a>Comentários

O Windows envia `WM_INITDIALOG` a mensagem para a caixa de diálogo durante as chamadas [criar](#create), [indireta](#createindirect)ou [DoModal](#domodal) , que ocorrem imediatamente antes de a caixa de diálogo ser exibida.

Substitua esse método se desejar executar processamento especial quando a caixa de diálogo for inicializada. Na versão substituída, primeiro chame a classe `OnInitDialog` base, mas ignore seu valor de retorno. Normalmente, você retornará `TRUE` do seu método substituído.

O Windows chama `OnInitDialog` a função usando o procedimento de caixa de diálogo global padrão comum a todas as caixas de diálogo de biblioteca MFC. Ele não chama essa função por meio de seu mapa de mensagens e, portanto, você não precisa de uma entrada de mapa de mensagem para esse método.

> [!NOTE]
> Não é possível substituir esse método quando você usa `CFileDialog` um objeto em um programa que é compilado no Windows Vista ou em sistemas operacionais posteriores. Para obter mais informações sobre alterações `CFileDialog` em no Windows Vista e posterior, consulte [classe CFileDialog](../../mfc/reference/cfiledialog-class.md).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCControlLadenDialog#67](../../mfc/codesnippet/cpp/cdialog-class_6.cpp)]

##  <a name="onok"></a>CDialog:: OnOK

Chamado quando o usuário clica no botão **OK** (o botão com uma ID de IDOK).

```
virtual void OnOK();
```

### <a name="remarks"></a>Comentários

Substitua esse método para executar ações quando o botão **OK** for ativado. Se a caixa de diálogo incluir a validação automática de dados e o Exchange, a implementação padrão desse método validará os dados da caixa de diálogo e atualizará as variáveis apropriadas em seu aplicativo.

Se você implementar o botão **OK** em uma caixa de diálogo sem janela restrita, deverá substituir `OnOK` o método e chamar [DestroyWindow](../../mfc/reference/cwnd-class.md#destroywindow) dentro dele. Não chame o método de classe base, pois ele chama [EndDialog](#enddialog) , o que torna a caixa de diálogo invisível, mas não a destrói.

> [!NOTE]
>  Não é possível substituir esse método quando você usa `CFileDialog` um objeto em um programa que é compilado no Windows XP. Para obter mais informações `CFileDialog`sobre, consulte [classe CFileDialog](../../mfc/reference/cfiledialog-class.md).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCControlLadenDialog#68](../../mfc/codesnippet/cpp/cdialog-class_7.cpp)]

##  <a name="onsetfont"></a>  CDialog::OnSetFont

Especifica a fonte que um controle de caixa de diálogo usará ao desenhar o texto.

```
Virtual void OnSetFont(CFont* pFont);
```

### <a name="parameters"></a>Parâmetros

*pFont*<br/>
no Especifica um ponteiro para a fonte que será usada como a fonte padrão para todos os controles nessa caixa de diálogo.

### <a name="remarks"></a>Comentários

A caixa de diálogo usará a fonte especificada como o padrão para todos os seus controles.

Normalmente, o editor de caixa de diálogo define a fonte do box de caixas de diálogo como parte do recurso de modelo de caixa de dialogo.

> [!NOTE]
> Não é possível substituir esse método quando você usa `CFileDialog` um objeto em um programa que é compilado no Windows Vista ou em sistemas operacionais posteriores. Para obter mais informações sobre alterações `CFileDialog` em no Windows Vista e posterior, consulte [classe CFileDialog](../../mfc/reference/cfiledialog-class.md).

##  <a name="prevdlgctrl"></a>CDialog::P revDlgCtrl

Define o foco para o controle anterior na caixa de diálogo.

```
void PrevDlgCtrl() const;
```

### <a name="remarks"></a>Comentários

Se o foco estiver no primeiro controle na caixa de diálogo, ele passará para o último controle na caixa.

##  <a name="setdefid"></a>CDialog:: SetDefID

Altera o controle de pressão padrão para uma caixa de diálogo.

```
void SetDefID(UINT nID);
```

### <a name="parameters"></a>Parâmetros

*nID*<br/>
Especifica a ID do controle de supressão que se tornará o padrão.

##  <a name="sethelpid"></a>CDialog:: sethelpid

Define uma ID de ajuda sensível ao contexto para a caixa de diálogo.

```
void SetHelpID(UINT nIDR);
```

### <a name="parameters"></a>Parâmetros

*nIDR*<br/>
Especifica a ID da ajuda sensível ao contexto.

## <a name="see-also"></a>Consulte também

[Exemplo de DLGCBR32 do MFC](../../overview/visual-cpp-samples.md)<br/>
[Exemplo de DLGTEMPL do MFC](../../overview/visual-cpp-samples.md)<br/>
[Classe CWnd](../../mfc/reference/cwnd-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)
