---
title: Adicionar uma variável de membro
ms.date: 11/09/2018
f1_keywords:
- vc.codewiz.classes.member.variable
- vc.codewiz.variable.overview
helpviewer_keywords:
- member variables, adding
- member variables
- add member variable wizard [C++]
- dialog box controls, member variables
- dialog box controls, variable types
- variables, dialog box control member variables
ms.assetid: 437783bd-8eb4-4508-8b73-7380116e9d71
ms.openlocfilehash: 2a519c0606a7df6e0ce55997a055d78865afafbf
ms.sourcegitcommit: b032daf81cb5fdb1f5a988277ee30201441c4945
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/15/2018
ms.locfileid: "51694407"
---
# <a name="add-a-member-variable"></a>Adicionar uma variável de membro

É possível adicionar uma variável de membro a uma classe usando o Modo de Exibição de Classe. As variáveis de membro podem se destinar à [troca e à validação de dados](../mfc/dialog-data-exchange-and-validation.md) ou podem ser genéricas. O assistente de variável de membro de dados foi projetado para encontrar as informações relevantes e usá-las para inserir elementos nos arquivos de origem nos locais apropriados. É possível adicionar uma variável de membro por meio do [Editor de caixas de diálogo](../windows/dialog-editor.md) em [Modo de Exibição de Recursos](../windows/resource-view-window.md) ou por meio de [Modo de Exibição de Classe](/visualstudio/ide/viewing-the-structure-of-code).

> [!NOTE]
> Quando está projetando e implementando uma caixa de diálogo, talvez seja mais eficiente usar o Editor de caixas de diálogo para adicionar os controles de caixa de diálogo e, em seguida, implementar as variáveis de membro dos controles.

**Para adicionar uma variável de membro a um controle de caixa de diálogo em Modo de Exibição de Recursos usando o Assistente de Adição de Variável de Membro:**

1. Em Modo de Exibição de Recursos, expanda o nó do projeto e o nó Caixa de Diálogo para exibir a lista de caixas de diálogo do projeto.

1. Clique duas vezes na caixa de diálogo à qual deseja adicionar a variável de membro para abri-la no Editor de caixas de diálogo.

1. Na caixa de diálogo exibida no Editor de caixas de diálogo, clique com o botão direito do mouse no controle ao qual deseja adicionar a variável de membro.

1. No menu de atalho, escolha **Adicionar Variável** para exibir o [Assistente de adição de variável de membro](#add-member-variable-wizard).

   > [!NOTE]
   > Um valor padrão já é fornecido em **ID de Controle**.

1. Forneça as informações nas caixas apropriadas do assistente. Para obter mais informações, confira [controles de caixa de diálogo e tipos de variáveis](#dialog-box-controls-and-variable-types).

1. Selecione **Concluir** para adicionar o código de definição e de implementação ao projeto e fechar o assistente.

**Para adicionar uma variável de membro por meio do Modo de Exibição de Classe usando o Assistente de Adição de Variável de Membro:**

1. Em [Modo de Exibição de Classe](/visualstudio/ide/viewing-the-structure-of-code), expanda o nó do projeto para exibir as classes no projeto.

1. Clique com o botão direito do mouse na classe à qual deseja adicionar uma variável.

1. No menu de atalho, escolha **Adicionar** e, em seguida, **Adicionar Variável** para exibir o Assistente de Adição de Variável de Membro.

1. Forneça as informações nas caixas apropriadas do assistente. Para obter mais informações, confira [Assistente de adição de variável de membro](#add-member-variable-wizard).

1. Selecione **Concluir** para adicionar o código de definição e de implementação ao projeto e fechar o assistente.

## <a name="in-this-section"></a>Nesta seção

- [Assistente de adição de variável de membro](#add-member-variable-wizard)
- [Controles da caixa de diálogo e tipos de variável](#dialog-box-controls-and-variable-types)

## <a name="add-member-variable-wizard"></a>Assistente de adição de variável de membro

Este assistente adiciona uma declaração de variável de membro ao arquivo de cabeçalho. Dependendo das opções, pode adicionar código ao arquivo .cpp. Depois de adicionar a variável de membro usando o assistente, edite o código no ambiente de desenvolvimento.

- **Access**

  Define o acesso à variável de membro. Modificadores de acesso são palavras-chave que especificam o acesso que outras classes têm à variável de membro. Para obter mais informações sobre como especificar o acesso, confira [controle de acesso a membro](../cpp/member-access-control-cpp.md). O nível de acesso da variável de membro é definido como `public` por padrão.

  - [public](../cpp/public-cpp.md)
  - [protected](../cpp/protected-cpp.md)
  - [private](../cpp/private-cpp.md)

- **Tipo de variável**

  Define o tipo de retorno da variável de membro que está sendo adicionada.

  - Se estiver adicionando uma variável de membro que não é um controle de caixa de diálogo, selecione uma opção na lista de tipos disponíveis.

    Para obter informações sobre os tipos, confira [tipos fundamentais](../cpp/fundamental-types-cpp.md).

    |||
    |-|-|
    |`char`|`short`|
    |`double`|`unsigned char`|
    |`float`|`unsigned int`|
    |`int`|`unsigned long`|
    |`long`||

  - Se estiver adicionando uma variável de membro a um controle de caixa de diálogo, essa caixa será preenchida com o tipo do objeto que é retornado para um controle ou um valor. Se você selecionar **Controle**, a opção **Tipo de variável** especificará a classe base do controle selecionado na caixa **ID de Controle**. Se o controle de caixa de diálogo puder guardar um valor e você selecionar **Valor**, a opção **Tipo de variável** especificará o tipo apropriado para o valor que o controle pode guardar. Para obter mais informações, confira [controles de caixa de diálogo e tipos de variáveis](#dialog-box-controls-and-variable-types).

    Esse valor depende da seleção em **ID de Controle** e não pode ser alterado.

- **Nome da variável**

  Define o nome da variável de membro que está sendo adicionada. Normalmente, as variáveis de membro começam com a cadeia de caracteres de identificação `m_`, que é fornecida para você por padrão.

- **Variável de controle**

  Indica que a variável de membro gerencia um controle em uma caixa de diálogo com o suporte da [troca e validação de dados](../mfc/dialog-data-exchange-and-validation.md). Para obter mais informações, confira [DoDataExchange](../mfc/reference/cwnd-class.md#dodataexchange). Essa opção está disponível somente para as variáveis de membro adicionadas às classes derivadas de [CDialog](../mfc/reference/cdialog-class.md). Marque essa caixa para ativar as opções **ID de Controle** e **Tipo de controle**.

- **ID de Controle**

  Define a ID para a variável de controle que está sendo adicionada. Selecione na lista a ID do tipo de controle ao qual a variável de membro está sendo adicionada. A lista fica ativa somente quando a caixa **Variável de controle** está selecionada e é limitada às IDs dos controles que já foram adicionados à caixa de diálogo. Por exemplo, para o botão **OK** padrão, a ID de Controle é **IDOK**.

  |Opção|Descrição|
  |------------|-----------------|
  |**Controle**|Essa opção está definida por padrão para o tipo de controle. Ela gerencia o próprio controle e não o estado nem o conteúdo do controle (como talvez você deseje fazer com uma caixa de listagem, caixa de combinação ou caixa de edição).|
  |**Valor**|Essa opção está disponível para tipos de controle que podem conter um valor ou mostrar um estado, como uma caixa de edição ou uma caixa de seleção. Também está disponível para tipos de controle para os quais você pode gerenciar o intervalo, o conteúdo ou o estado. Para obter mais informações, confira [controles de caixa de diálogo e tipos de variáveis](#dialog-box-controls-and-variable-types).|

- **Categoria**

  Especifica se a variável baseia-se em um tipo de controle ou no valor do controle.

- **Tipo de controle**

  Define o tipo de controle que está sendo adicionado. Essa caixa não está disponível para alteração. Por exemplo, um botão tem o tipo de controle **BUTTON**, e uma caixa de combinação tem o tipo de controle **COMBOBOX**. Para obter mais informações, confira [controles de caixa de diálogo e tipos de variáveis](#dialog-box-controls-and-variable-types).

- **Número máx. de caracteres**

  Disponível somente quando a opção **Tipo de variável** é definida como [CString](../atl-mfc-shared/reference/cstringt-class.md). Indica o número máximo de caracteres que o controle pode conter.

- **Valor mín.**

  Disponível apenas quando o tipo de variável é `BOOL`, `int`, `UINT`, `long`, `DWORD`, `float`, `double`, `BYTE`, `short`, [COLECurrency](../mfc/reference/colecurrency-class.md) ou [CTime](../atl-mfc-shared/reference/ctime-class.md). Indica o menor valor aceitável para uma escala ou um intervalo de datas.

- **Valor máx.**

  Disponível apenas quando o tipo de variável é `BOOL`, `int`, `UINT`, `long`, `DWORD`, `float`, `double`, `BYTE`, `short`, `COLECurrency` ou `CTime`. Indica o maior valor aceitável para uma escala ou um intervalo de datas.

- **Arquivo .h**

  Para controles ActiveX, cujas variáveis de membro exigem uma classe wrapper. Define o nome do arquivo de cabeçalho para adicionar a declaração de classe.

- **Arquivo .cpp**

  Para controles ActiveX, cujas variáveis de membro exigem uma classe wrapper. Define o nome do arquivo de implementação para adicionar a definição de classe.

- **Comentário**

  Fornece um comentário no arquivo de cabeçalho da variável de membro.

## <a name="dialog-box-controls-and-variable-types"></a>Controles da caixa de diálogo e tipos de variável

Use o [assistente de adição de variável de membro](#add-member-variable-wizard) para adicionar uma variável de membro a um controle de caixa de diálogo criado usando o MFC. O tipo de controle ao qual você adiciona a variável de membro determina as opções exibidas na caixa de diálogo.

A tabela a seguir descreve todos os tipos de controle de caixa de diálogo compatíveis com o MFC e o [Editor de caixas de diálogo](../windows/dialog-editor.md). Também exibe os tipos e valores disponíveis.

|Controle|Tipo de controle|Tipo de variável de controle|Tipo de variável de valor|Valores mín./máx. (somente tipo de valor)|
|-------------|------------------|---------------------------|-------------------------|-----------------------------------------|
|Controle de animação|SysAnimate32|[CAnimateCtrl](../mfc/reference/canimatectrl-class.md)|Nenhum; somente controle|N/D|
|Botão|BUTTON|[CButton](../mfc/reference/cbutton-class.md)|Nenhum; somente controle|N/D|
|Caixa de seleção|CHECK|[CButton](../mfc/reference/cbutton-class.md)|`BOOL`|Valor mín./valor máx.|
|Caixa de combinação|COMBOBOX|[CComboBox](../mfc/reference/ccombobox-class.md)|[CString](../atl-mfc-shared/reference/cstringt-class.md)|Número máx. de caracteres|
|Controle de seletor de data e hora|SysDateTimePick32|[CDateTimeCtrl](../mfc/reference/cdatetimectrl-class.md)|[CTime](../atl-mfc-shared/reference/ctime-class.md)|Valor mín./valor máx.|
|Caixa de edição|EDIT|[CEdit](../mfc/reference/cedit-class.md)|`CString`, int, UINT, long, DWORD, float, double, BYTE, short, BOOL, `COleDateTime` ou `COleCurrency`|Valor mín./valor máx.; alguns dão suporte ao número máximo de caracteres|
|Controle de tecla de acesso|msctls_hotkey32|[CHotKeyCtrl](../mfc/reference/chotkeyctrl-class.md)|Nenhum; somente controle|N/D|
|Caixa de listagem|LISTBOX|[CListBox](../mfc/reference/clistbox-class.md)|`CString`|Número máx. de caracteres|
|Controle de lista|SysListView32|[CListCtrl](../mfc/reference/clistctrl-class.md)|Nenhum; somente controle|N/D|
|Controle de calendário mensal|SysMonthCal32|[CMonthCalCtrl](../mfc/reference/cmonthcalctrl-class.md)|`CTime`|Valor mín./valor máx.|
|Controle de progresso|msctls_progress32|[CProgressCtrl](../mfc/reference/cprogressctrl-class.md)|Nenhum; somente controle|N/D|
|Controle de Rich Edit 2|RichEdit20A|[CRichEditCtrl](../mfc/reference/cricheditctrl-class.md)|`CString`|Número máx. de caracteres|
|Controle de Rich Edit|RICHEDIT|`CRichEditCtrl`|`CString`|Número máx. de caracteres|
|Barra de rolagem (vertical ou horizontal)|SCROLLBAR|[CScrollBar](../mfc/reference/cscrollbar-class.md)|`int`|Valor mín./valor máx.|
|Controle deslizante|msctls_trackbar32|[CSliderCtrl](../mfc/reference/csliderctrl-class.md)|`int`|Valor mín./valor máx.|
|Controle de giro|msctls_updown32|[CSpinButtonCtrl](../mfc/reference/cspinbuttonctrl-class.md)|Nenhum; somente controle|N/D|
|Controle guia|SysTabControl32|[CTabCtrl](../mfc/reference/ctabctrl-class.md)|Nenhum; somente controle|N/D|
|Controle de árvore|SysTreeView32|[CTreeCtrl](../mfc/reference/ctreectrl-class.md)|Nenhum; somente controle|N/D|
