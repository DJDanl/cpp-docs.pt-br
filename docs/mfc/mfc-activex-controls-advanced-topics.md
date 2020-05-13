---
title: 'Controles ActiveX MFC: tópicos avançados'
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
ms.openlocfilehash: c5e3be3915a0707f8df17d3c9ebe2eb0e4f623b2
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81364636"
---
# <a name="mfc-activex-controls-advanced-topics"></a>Controles ActiveX MFC: tópicos avançados

Este artigo aborda tópicos avançados relacionados ao desenvolvimento de controles ActiveX. Eles incluem:

- [Usando classes de banco de dados em controles ActiveX](#_core_using_database_classes_in_activex_controls)

- [Implementando uma Propriedade Parametrizada](#_core_implementing_a_parameterized_property)

- [Erros de manuseio no controle do ActiveX](#_core_handling_errors_in_your_activex_control)

- [Manuseio de chaves especiais no controle](#_core_handling_special_keys_in_your_control)

- [Acessando controles de diálogo que são invisíveis no tempo de execução](#_core_accessing_dialog_controls_that_are_invisible_at_run_time)

>[!IMPORTANT]
> ActiveX é uma tecnologia herdada que não deve ser usada para novos desenvolvimentos. Para obter mais informações sobre tecnologias modernas que substituim o ActiveX, consulte [ActiveX Controls](activex-controls.md).

## <a name="using-database-classes-in-activex-controls"></a><a name="_core_using_database_classes_in_activex_controls"></a>Usando classes de banco de dados em controles ActiveX

Como as classes de controle ActiveX fazem parte da biblioteca de classes, você pode aplicar os mesmos procedimentos e regras para usar classes de banco de dados em um aplicativo Padrão De MFC para desenvolver controles ActiveX que usam as classes de banco de dados MFC.

Para obter uma visão geral das classes de banco de dados do MFC, consulte [Classes de Banco de Dados MFC (DAO e ODBC)](../data/mfc-database-classes-odbc-and-dao.md). O artigo introduz as classes MFC ODBC e as classes DAO do MFC e direciona você para mais detalhes sobre ambos.

> [!NOTE]
> O DAO é suportado através do Office 2013. DAO 3.6 é a versão final, e é considerada obsoleta. O ambiente Visual C++ e os assistentes não suportam DAO (embora as classes DAO estejam incluídas e você ainda possa usá-las). A Microsoft recomenda que você use [Modelos OLE DB](../data/oledb/ole-db-programming.md) ou [ODBC e MFC](../data/odbc/odbc-and-mfc.md) para novos projetos. Você só deve usar DAO na manutenção de aplicativos existentes.

## <a name="implementing-a-parameterized-property"></a><a name="_core_implementing_a_parameterized_property"></a>Implementando uma Propriedade Parametrizada

Uma propriedade parametrizada (às vezes chamada de matriz de propriedades) é um método para expor uma coleção homogênea de valores como uma única propriedade do controle. Por exemplo, você pode usar uma propriedade parametrizada para expor uma matriz ou um dicionário como propriedade. No Visual Basic, tal propriedade é acessada usando notação de matriz:

[!code-vb[NVC_MFC_AxVb#1](../mfc/codesnippet/visualbasic/mfc-activex-controls-advanced-topics_1.vb)]

Use o Assistente adicionar propriedade para implementar uma propriedade parametrizada. O Assistente de Propriedade adicionar implementa a propriedade adicionando um par de funções Get/Set que permitem ao usuário de controle acessar a propriedade usando a notação acima ou na forma padrão.

Semelhante aos métodos e propriedades, as propriedades parametrizadas também têm um limite para o número de parâmetros permitidos. No caso de propriedades parametrizadas, o limite é de 15 parâmetros (com um parâmetro reservado para armazenar o valor do imóvel).

O procedimento a seguir adiciona uma propriedade parametrizada, chamada Array, que pode ser acessada como uma matriz bidimensional de inteiros.

#### <a name="to-add-a-parameterized-property-using-the-add-property-wizard"></a>Para adicionar uma propriedade parametrizada usando o Assistente adicionar propriedade

1. Carregue o projeto do seu controle.

1. Em Class View, expanda o nó de biblioteca do seu controle.

1. Clique com o botão direito do mouse no nó de interface para o seu controle (o segundo nó do nó da biblioteca) para abrir o menu de atalho.

1. No menu de atalho, clique **em Adicionar** e clique em **Adicionar propriedade**.

1. Na **caixa Nome da propriedade,** digite `Array`.

1. Na caixa **Tipo de propriedade,** selecione **curto**.

1. Para o tipo **de implementação,** clique **em Obter/Definir Métodos**.

1. Nas caixas **'Obter função** e **definir funções',** digite nomes exclusivos para suas Funções Get e Set ou aceite os nomes padrão.

1. Adicione um parâmetro, chamado *linha* (tipo *curto),* usando os controles **Nome do parâmetro** e tipo de **parâmetro.**

1. Adicionar um segundo parâmetro chamado *coluna* (tipo *curto*).

1. Clique em **Concluir**.

### <a name="changes-made-by-the-add-property-wizard"></a>Alterações feitas pelo Assistente de Adicionar Propriedades

Quando você adiciona uma propriedade personalizada, o Assistente adicionar propriedades faz alterações no cabeçalho da classe de controle (. H) e a implementação (. CPP) arquivos.

As seguintes linhas são adicionadas à classe de controle . Arquivo H:

[!code-cpp[NVC_MFC_AxUI#35](../mfc/codesnippet/cpp/mfc-activex-controls-advanced-topics_2.h)]

Este código declara duas `GetArray` funções chamadas e `SetArray` que permitem ao usuário solicitar uma linha e coluna específicas ao acessar a propriedade.

Além disso, o Assistente adicionar propriedades adiciona as seguintes linhas ao mapa de despacho de controle, localizado na implementação da classe de controle (. Arquivo CPP):

[!code-cpp[NVC_MFC_AxUI#36](../mfc/codesnippet/cpp/mfc-activex-controls-advanced-topics_3.cpp)]

Finalmente, as implementações `GetArray` `SetArray` e funções são adicionadas ao final do . Arquivo CPP. Na maioria dos casos, você modificará a função Get para devolver o valor da propriedade. A função Definir geralmente conterá código que deve ser executado, antes ou depois das alterações de propriedade.

Para que esta propriedade seja útil, você pode declarar uma variável de membro de matriz bidimensional na classe de controle, do tipo **curto,** para armazenar valores para a propriedade parametrizada. Em seguida, você pode modificar a função Get para retornar o valor armazenado na linha e coluna adequadas, conforme indicado pelos parâmetros, e modificar a função Definir para atualizar o valor referenciado pelos parâmetros de linha e coluna.

## <a name="handling-errors-in-your-activex-control"></a><a name="_core_handling_errors_in_your_activex_control"></a>Erros de manuseio no controle do ActiveX

Se ocorrerem condições de erro no controle, talvez seja necessário relatar o erro ao recipiente de controle. Existem dois métodos para reportar erros, dependendo da situação em que o erro ocorre. Se o erro ocorrer dentro da função Get ou Set de uma propriedade, ou dentro da implementação de um método de Automação OLE, o controle deve chamar [COleControl::ThrowError](../mfc/reference/colecontrol-class.md#throwerror), que sinaliza ao usuário de controle que ocorreu um erro. Se o erro ocorrer em qualquer outro momento, o controle deve chamar [COleControl::FireError](../mfc/reference/colecontrol-class.md#fireerror), que dispara um evento de erro de estoque.

Para indicar o tipo de erro que ocorreu, o `ThrowError` controle `FireError`deve passar um código de erro para ou . Um código de erro é um código de status OLE, que tem um valor de 32 bits. Quando possível, escolha um código de erro do conjunto padrão de códigos definido no OLECTL. Arquivo h cabeçalho. A tabela a seguir resume esses códigos.

### <a name="activex-control-error-codes"></a>Códigos de erro do controle ActiveX

|Erro|Descrição|
|-----------|-----------------|
|CTL_E_ILLEGALFUNCTIONCALL|Chamada de função ilegal|
|CTL_E_OVERFLOW|Estouro|
|CTL_E_OUTOFMEMORY|Memória insuficiente|
|CTL_E_DIVISIONBYZERO|Divisão por zero|
|CTL_E_OUTOFSTRINGSPACE|Espaço insuficiente na cadeia de caracteres|
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
|CTL_E_BADFILENAME|Nome de arquivo ruim|
|CTL_E_TOOMANYFILES|Muitos arquivos|
|CTL_E_DEVICEUNAVAILABLE|Dispositivo não disponível|
|CTL_E_PERMISSIONDENIED|Permissão negada|
|CTL_E_DISKNOTREADY|O disco não está pronto|
|CTL_E_PATHFILEACCESSERROR|Erro de acesso de caminho/arquivo|
|CTL_E_PATHNOTFOUND|demarcador não localizado|
|CTL_E_INVALIDPATTERNSTRING|Cadeia de caracteres de padrão inválida|
|CTL_E_INVALIDUSEOFNULL|Uso inválido de NULL|
|CTL_E_INVALIDFILEFORMAT|Formato de arquivo inválido|
|CTL_E_INVALIDPROPERTYVALUE|Valor de propriedade inválido|
|CTL_E_INVALIDPROPERTYARRAYINDEX|Índice de matriz de propriedades inválida|
|CTL_E_SETNOTSUPPORTEDATRUNTIME|Não há suporte para Set em tempo de execução|
|CTL_E_SETNOTSUPPORTED|Não há suporte para Set (propriedade somente leitura)|
|CTL_E_NEEDPROPERTYARRAYINDEX|Índice da matriz de propriedade necessário|
|CTL_E_SETNOTPERMITTED|Definição não permitida|
|CTL_E_GETNOTSUPPORTEDATRUNTIME|Não há suporte para Get em tempo de execução|
|CTL_E_GETNOTSUPPORTED|Não há suporte para Get (propriedade somente gravação)|
|CTL_E_PROPERTYNOTFOUND|Propriedade não localizada|
|CTL_E_INVALIDCLIPBOARDFORMAT|Formato de área de transferência inválido|
|CTL_E_INVALIDPICTURE|Imagem inválida|
|CTL_E_PRINTERERROR|Erro de impressora|
|CTL_E_CANTSAVEFILETOTEMP|Não é possível salvar arquivo para TEMP|
|CTL_E_SEARCHTEXTNOTFOUND|Texto de pesquisa não encontrado|
|CTL_E_REPLACEMENTSTOOLONG|Substituições muito longas|

Se necessário, use a CUSTOM_CTL_SCODE macro para definir um código de erro personalizado para uma condição que não esteja coberta por um dos códigos padrão. O parâmetro para esta macro deve ser um inteiro entre 1000 e 32767, inclusive. Por exemplo:

[!code-cpp[NVC_MFC_AxUI#37](../mfc/codesnippet/cpp/mfc-activex-controls-advanced-topics_4.cpp)]

Se você estiver criando um controle ActiveX para substituir um controle VBX existente, defina os códigos de erro do controle ActiveX com os mesmos valores numéricos que o controle VBX usa para garantir que os códigos de erro sejam compatíveis.

## <a name="handling-special-keys-in-the-control"></a><a name="_core_handling_special_keys_in_your_control"></a>Manuseio de chaves especiais no controle

Em alguns casos, você pode querer lidar com certas combinações de teclas de uma maneira especial; por exemplo, insira uma nova linha quando a tecla ENTER for pressionada em um controle de caixa de texto multilinha ou mover-se entre um grupo de controles de edição quando uma iD de chave direcional pressionada.

Se a classe base do `COleControl`controle ActiveX for, você pode substituir [CWnd::PreTranslateMessage](../mfc/reference/cwnd-class.md#pretranslatemessage) para lidar com mensagens antes que o contêiner as processe. Ao usar esta técnica, sempre retorne **TRUE** se você `PreTranslateMessage`manusear a mensagem em sua substituição de .

O exemplo de código a seguir demonstra uma possível maneira de lidar com quaisquer mensagens relacionadas com as teclas direcionais.

[!code-cpp[NVC_MFC_AxUI#38](../mfc/codesnippet/cpp/mfc-activex-controls-advanced-topics_5.cpp)]

Para obter mais informações sobre como manusear interfaces de teclado para um controle ActiveX, consulte a documentação do ActiveX SDK.

## <a name="accessing-dialog-controls-that-are-invisible-at-run-time"></a><a name="_core_accessing_dialog_controls_that_are_invisible_at_run_time"></a>Acessando controles de diálogo que são invisíveis no tempo de execução

Você pode criar controles de diálogo que não têm interface de usuário e são invisíveis em tempo de execução. Se você adicionar um controle ActiveX invisível em tempo de execução a uma caixa de diálogo e usar [CWnd::GetDlgItem](../mfc/reference/cwnd-class.md#getdlgitem) para acessar o controle, o controle não funcionará corretamente. Em vez disso, você deve usar uma das seguintes técnicas para obter um objeto que represente o controle:

- Usando o Assistente de Variável adicionar membro, selecione **'Variável de controle'** e selecione o ID do controle. Digite um nome de variável de membro e selecione a classe de invólucro do controle como o **Tipo de Controle**.

     -ou-

- Declare uma variável local e uma subclasse como item de diálogo. Inserir código que se`CMyCtrl` assemelha ao seguinte (é a classe invólucro, IDC_MYCTRL1 é o ID do controle):

   [!code-cpp[NVC_MFC_AxCont#19](../mfc/codesnippet/cpp/mfc-activex-controls-advanced-topics_6.cpp)]

## <a name="see-also"></a>Confira também

[Controles ActiveX do MFC](../mfc/mfc-activex-controls.md)
