---
title: 'Controles ActiveX MFC: Tópicos avançados'
ms.date: 09/12/2018
helpviewer_keywords:
- MFC ActiveX controls [MFC], error codes
- MFC ActiveX controls [MFC], accessing invisible dialog controls
- MFC ActiveX controls [MFC], advanced topics
- FireError method [MFC]
- MFC ActiveX controls [MFC], database classes
- MFC ActiveX controls [MFC], special keys
- PreTranslateMessage method [MFC]
- MFC ActiveX controls [MFC], parameterized property
- ThrowError method [MFC]
ms.assetid: e9e34abb-8e2d-461e-bb9c-a1aec5dcecbd
ms.openlocfilehash: df71e2e59763644bd4aefb5d3e3afa46f82f538a
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62392707"
---
# <a name="mfc-activex-controls-advanced-topics"></a>Controles ActiveX MFC: Tópicos avançados

Este artigo aborda tópicos avançados relacionados ao desenvolvimento de controles ActiveX. Elas incluem:

- [Usando Classes de banco de dados em controles ActiveX](#_core_using_database_classes_in_activex_controls)

- [Implementando uma propriedade com parâmetros](#_core_implementing_a_parameterized_property)

- [Tratamento de erros em seu controle ActiveX](#_core_handling_errors_in_your_activex_control)

- [Manipulação de chaves especiais no controle](#_core_handling_special_keys_in_your_control)

- [Acessando controles de caixa de diálogo que são invisíveis no tempo de execução](#_core_accessing_dialog_controls_that_are_invisible_at_run_time)

>[!IMPORTANT]
> ActiveX é uma tecnologia herdada que não deve ser usada para novos desenvolvimentos. Para obter mais informações sobre tecnologias modernas que substituem o ActiveX, consulte [controles ActiveX](activex-controls.md).

##  <a name="_core_using_database_classes_in_activex_controls"></a> Usando Classes de banco de dados em controles ActiveX

Como as classes de controle ActiveX fazem parte da biblioteca de classes, você pode aplicar os mesmos procedimentos e as regras para usar classes de banco de dados em um aplicativo MFC padrão para o desenvolvimento de controles ActiveX que usam as classes de banco de dados do MFC.

Para obter uma visão geral das classes de banco de dados do MFC, consulte [Classes de banco de dados MFC (DAO e ODBC)](../data/mfc-database-classes-odbc-and-dao.md). O artigo apresenta as classes MFC ODBC e MFC DAO classes e direciona você para obter mais detalhes sobre qualquer um.

> [!NOTE]
>  Os assistentes e o ambiente do Visual C++ não têm suporte DAO (embora as classes DAO estão incluídas e você ainda pode usá-los). A Microsoft recomenda que você use [modelos OLE DB](../data/oledb/ole-db-programming.md) ou [ODBC e MFC](../data/odbc/odbc-and-mfc.md) para novos projetos. Você só deve usar DAO em manutenção de aplicativos existentes.

##  <a name="_core_implementing_a_parameterized_property"></a> Implementando uma propriedade com parâmetros

Uma propriedade com parâmetros (às vezes chamada de uma matriz de propriedade) é um método para expor uma coleção homogênea de valores como uma única propriedade do controle. Por exemplo, você pode usar uma propriedade com parâmetros para expor um dicionário como uma propriedade ou uma matriz. No Visual Basic, essa propriedade é acessada usando a notação de matriz:

[!code-vb[NVC_MFC_AxVb#1](../mfc/codesnippet/visualbasic/mfc-activex-controls-advanced-topics_1.vb)]

Use o Assistente para adicionar propriedade para implementar uma propriedade com parâmetros. O Assistente para adicionar propriedade implementa a propriedade adicionando um par de funções de Get/Set que permitem que o usuário acessar a propriedade usando a notação acima do controle ou da maneira padrão.

Semelhante aos métodos e propriedades, propriedades parametrizadas também têm um limite para o número de parâmetros permitidos. No caso de propriedades parametrizadas, o limite é de 15 parâmetros (com um parâmetro reservado para armazenar o valor da propriedade).

O procedimento a seguir adiciona uma propriedade com parâmetros, chamada matriz, que pode ser acessado como uma matriz bidimensional de inteiros.

#### <a name="to-add-a-parameterized-property-using-the-add-property-wizard"></a>Para adicionar uma propriedade com parâmetros usando o Assistente para adicionar propriedade

1. Carregar o projeto do seu controle.

1. No modo de exibição de classe, expanda o nó de biblioteca do seu controle.

1. Para abrir o menu de atalho, clique com botão direito no nó de interface para o seu controle (o segundo nó do nó de biblioteca).

1. No menu de atalho, clique em **Add** e, em seguida, clique em **adicionar propriedade**.

1. No **nome da propriedade** , digite `Array`.

1. No **tipo de propriedade** caixa, selecione **curto**.

1. Para **implementação** tipo, clique em **métodos Get/Set**.

1. No **função Obtenha** e **função Set** caixas, digite nomes exclusivos para seu Get e definir funções ou aceite os nomes padrão.

9. Adicione um parâmetro chamado *linha* (tipo *curto*), usando o **nome do parâmetro** e **tipo de parâmetro** controles.

10. Adicionar um segundo parâmetro chamado *coluna* (tipo *curto*).

11. Clique em **Finalizar**.

### <a name="changes-made-by-the-add-property-wizard"></a>As alterações feitas pelo Assistente para adicionar propriedade

Quando você adiciona uma propriedade personalizada, o Assistente para adicionar propriedade faz alterações para o cabeçalho de classe de controle (. H) e a implementação (. Arquivos CPP).

As linhas a seguir são adicionadas à classe do controle. Arquivo do H:

[!code-cpp[NVC_MFC_AxUI#35](../mfc/codesnippet/cpp/mfc-activex-controls-advanced-topics_2.h)]

Esse código declara duas funções chamadas `GetArray` e `SetArray` que permitem que o usuário solicitar uma linha e coluna específica ao acessar a propriedade.

Além disso, o Assistente para adicionar propriedade adiciona as seguintes linhas ao mapa de expedição de controle, na implementação de classe do controle (. Arquivo CPP):

[!code-cpp[NVC_MFC_AxUI#36](../mfc/codesnippet/cpp/mfc-activex-controls-advanced-topics_3.cpp)]

Por fim, as implementações do `GetArray` e `SetArray` funções são adicionadas ao final da. Arquivo CPP. Na maioria dos casos, você modificará a função Get para retornar o valor da propriedade. A função de conjunto geralmente conterá o código que deve executar antes ou após as alterações de propriedade.

Para essa propriedade é útil, você poderia declarar uma variável de membro na classe de controle do tipo de matriz bidimensional **curto**, para armazenar os valores da propriedade com parâmetros. Em seguida, você poderia modificar a função de Get para retornar o valor armazenado na linha apropriada e na coluna, conforme indicado pelos parâmetros e modifique a função de conjunto para atualizar o valor referenciado pelos parâmetros de linha e coluna.

##  <a name="_core_handling_errors_in_your_activex_control"></a> Tratamento de erros em seu controle ActiveX

Se ocorrerem as condições de erro no controle, você talvez precise relatar o erro para o contêiner de controle. Há dois métodos para relatar erros, dependendo da situação em que o erro ocorre. Se o erro ocorrer dentro de uma propriedade obter ou definir a função, ou dentro da implementação de um método de automação OLE, o controle deve chamar [COleControl::ThrowError](../mfc/reference/colecontrol-class.md#throwerror), que sinaliza para o usuário do controle que ocorreu um erro. Se o erro ocorrer em outra ocasião, o controle deve chamar [COleControl::FireError](../mfc/reference/colecontrol-class.md#fireerror), que dispara um evento de erro de estoque.

Para indicar o tipo de erro que ocorreu, o controle deve passar um código de erro para `ThrowError` ou `FireError`. Um código de erro é um código de status do OLE, que tem um valor de 32 bits. Quando possível, escolha um código de erro do conjunto padrão de códigos definidos no OLECTL. Arquivo de cabeçalho de H. A tabela a seguir resume esses códigos.

### <a name="activex-control-error-codes"></a>Códigos de erro do controle ActiveX

|Erro|Descrição|
|-----------|-----------------|
|CTL_E_ILLEGALFUNCTIONCALL|Chamada de função ilegal|
|CTL_E_OVERFLOW|Estouro|
|CTL_E_OUTOFMEMORY|Memória insuficiente|
|CTL_E_DIVISIONBYZERO|Divisão por zero|
|CTL_E_OUTOFSTRINGSPACE|Sem espaço de cadeia de caracteres|
|CTL_E_OUTOFSTACKSPACE|Espaço em pilha insuficiente|
|CTL_E_BADFILENAMEORNUMBER|Nome ou número de arquivo inválido|
|CTL_E_FILENOTFOUND|Arquivo não encontrado|
|CTL_E_BADFILEMODE|Modo de arquivo inválido|
|CTL_E_FILEALREADYOPEN|Arquivo já aberto|
|CTL_E_DEVICEIOERROR|Erro de E/S do dispositivo|
|CTL_E_FILEALREADYEXISTS|O arquivo já existe|
|CTL_E_BADRECORDLENGTH|Comprimento de registro inválido|
|CTL_E_DISKFULL|Disco cheio|
|CTL_E_BADRECORDNUMBER|Número de registro inválido|
|CTL_E_BADFILENAME|Nome de arquivo inválido|
|CTL_E_TOOMANYFILES|Muitos arquivos|
|CTL_E_DEVICEUNAVAILABLE|Dispositivo não disponível|
|CTL_E_PERMISSIONDENIED|Permissão negada|
|CTL_E_DISKNOTREADY|Disco não está pronto|
|CTL_E_PATHFILEACCESSERROR|Erro de acesso do caminho/arquivo|
|CTL_E_PATHNOTFOUND|demarcador não localizado|
|CTL_E_INVALIDPATTERNSTRING|Cadeia de caracteres padrão inválida|
|CTL_E_INVALIDUSEOFNULL|Uso inválido de nulo|
|CTL_E_INVALIDFILEFORMAT|Formato de arquivo inválido|
|CTL_E_INVALIDPROPERTYVALUE|Valor de propriedade inválido|
|CTL_E_INVALIDPROPERTYARRAYINDEX|Índice de matriz de propriedade inválido|
|CTL_E_SETNOTSUPPORTEDATRUNTIME|Conjunto não tem suportado em tempo de execução|
|CTL_E_SETNOTSUPPORTED|Conjunto não tem suportado (propriedade somente leitura)|
|CTL_E_NEEDPROPERTYARRAYINDEX|Índice da matriz de propriedade necessário|
|CTL_E_SETNOTPERMITTED|Definição não permitida|
|CTL_E_GETNOTSUPPORTEDATRUNTIME|Obter não tem suporte em tempo de execução|
|CTL_E_GETNOTSUPPORTED|Obter sem suporte (propriedade de somente gravação)|
|CTL_E_PROPERTYNOTFOUND|Propriedade não localizada|
|CTL_E_INVALIDCLIPBOARDFORMAT|Formato inválido de área de transferência|
|CTL_E_INVALIDPICTURE|Imagem inválida|
|CTL_E_PRINTERERROR|Erro de impressora|
|CTL_E_CANTSAVEFILETOTEMP|Não é possível salvar o arquivo para TEMP|
|CTL_E_SEARCHTEXTNOTFOUND|Texto de pesquisa não encontrado|
|CTL_E_REPLACEMENTSTOOLONG|Substituições muito longas|

Se necessário, use a macro CUSTOM_CTL_SCODE para definir um código de erro personalizado para uma condição que não é coberto por um dos códigos padrão. O parâmetro dessa macro deve ser um inteiro entre 1000 e 32767, inclusivo. Por exemplo:

[!code-cpp[NVC_MFC_AxUI#37](../mfc/codesnippet/cpp/mfc-activex-controls-advanced-topics_4.cpp)]

Se você estiver criando um controle ActiveX para substituir um controle existente do VBX, defina os códigos de erro do controle ActiveX com os mesmos valores numéricos, que o controle VBX usa para garantir que os códigos de erro são compatíveis.

##  <a name="_core_handling_special_keys_in_your_control"></a> Manipulação de chaves especiais no controle

Em alguns casos você talvez queira manipular determinadas combinações de pressionamento de tecla de forma especial; Por exemplo, inserir uma nova linha quando a tecla ENTER é pressionada em um texto de várias linhas, controle de caixa ou mover entre um grupo de edição controla quando um direcional pressionado de ID da chave.

Se a classe base do seu controle ActiveX `COleControl`, você pode substituir [CWnd::PreTranslateMessage](../mfc/reference/cwnd-class.md#pretranslatemessage) para lidar com mensagens antes que o contêiner as processa. Ao usar essa técnica, sempre retornam **verdadeira** se você manipular a mensagem em seu substituto do `PreTranslateMessage`.

O exemplo de código a seguir demonstra uma possível maneira de lidar com todas as mensagens relacionadas às chaves direcionais.

[!code-cpp[NVC_MFC_AxUI#38](../mfc/codesnippet/cpp/mfc-activex-controls-advanced-topics_5.cpp)]

Para obter mais informações sobre o tratamento de interfaces de teclado para um controle ActiveX, consulte a documentação do SDK do ActiveX.

##  <a name="_core_accessing_dialog_controls_that_are_invisible_at_run_time"></a> Acessando controles de caixa de diálogo que são invisíveis no tempo de execução

Você pode criar controles de caixa de diálogo que não tem nenhuma interface do usuário e são invisível em tempo de execução. Se você adicionar um invisível em tempo de execução controle ActiveX a uma caixa de diálogo e use [CWnd::GetDlgItem](../mfc/reference/cwnd-class.md#getdlgitem) para o controle de acesso, o controle não funcionará corretamente. Em vez disso, você deve usar uma das técnicas a seguir para obter um objeto que representa o controle:

- Usando o Assistente de adição membro variável, selecione **variável de controle** e, em seguida, selecione a ID. do controle Insira um nome de variável de membro e selecione a classe de wrapper do controle como o **tipo de controle**.

     - ou -

- Declare uma variável local e a subclasse como o item de caixa de diálogo. Inserir código semelhante ao seguinte (`CMyCtrl` é a classe de wrapper, IDC_MYCTRL1 é a ID do controle):

   [!code-cpp[NVC_MFC_AxCont#19](../mfc/codesnippet/cpp/mfc-activex-controls-advanced-topics_6.cpp)]

## <a name="see-also"></a>Consulte também

[Controles ActiveX do MFC](../mfc/mfc-activex-controls.md)
