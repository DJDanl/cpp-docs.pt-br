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
ms.openlocfilehash: 5ae29ed40d9cc5b78945fb9846a36d6b5a0b27d7
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87225027"
---
# <a name="mfc-activex-controls-advanced-topics"></a>Controles ActiveX MFC: tópicos avançados

Este artigo aborda tópicos avançados relacionados ao desenvolvimento de controles ActiveX. Elas incluem:

- [Usando classes de banco de dados em controles ActiveX](#_core_using_database_classes_in_activex_controls)

- [Implementando uma propriedade parametrizada](#_core_implementing_a_parameterized_property)

- [Tratamento de erros em seu controle ActiveX](#_core_handling_errors_in_your_activex_control)

- [Manipulando chaves especiais no controle](#_core_handling_special_keys_in_your_control)

- [Acessando controles de caixa de diálogo que são invisíveis em tempo de execução](#_core_accessing_dialog_controls_that_are_invisible_at_run_time)

>[!IMPORTANT]
> O ActiveX é uma tecnologia herdada que não deve ser usada para novos desenvolvimentos. Para obter mais informações sobre as tecnologias modernas que substituem o ActiveX, consulte [controles ActiveX](activex-controls.md).

## <a name="using-database-classes-in-activex-controls"></a><a name="_core_using_database_classes_in_activex_controls"></a>Usando classes de banco de dados em controles ActiveX

Como as classes de controle ActiveX fazem parte da biblioteca de classes, você pode aplicar os mesmos procedimentos e regras para usar classes de banco de dados em um aplicativo MFC padrão para desenvolver controles ActiveX que usam as classes de banco de dados MFC.

Para obter uma visão geral das classes de banco de dados MFC, consulte [classes de banco de dados MFC (DAO e ODBC)](../data/mfc-database-classes-odbc-and-dao.md). O artigo apresenta as classes ODBC do MFC e as classes do MFC DAO e direciona você para obter mais detalhes sobre ambos.

> [!NOTE]
> O DAO tem suporte por meio do Office 2013. O DAO 3,6 é a versão final e é considerado obsoleto. O ambiente Visual C++ e os assistentes não dão suporte a DAO (embora as classes DAO estejam incluídas e você ainda possa usá-las). A Microsoft recomenda que você use [modelos de OLE DB](../data/oledb/ole-db-programming.md) ou [ODBC e MFC](../data/odbc/odbc-and-mfc.md) para novos projetos. Você só deve usar o DAO na manutenção de aplicativos existentes.

## <a name="implementing-a-parameterized-property"></a><a name="_core_implementing_a_parameterized_property"></a>Implementando uma propriedade parametrizada

Uma propriedade parametrizada (às vezes chamada de matriz de propriedade) é um método para expor uma coleção homogênea de valores como uma única propriedade do controle. Por exemplo, você pode usar uma propriedade com parâmetros para expor uma matriz ou um dicionário como uma propriedade. Em Visual Basic, essa propriedade é acessada usando a notação de matriz:

[!code-vb[NVC_MFC_AxVb#1](codesnippet/visualbasic/mfc-activex-controls-advanced-topics_1.vb)]

Use o assistente para adicionar propriedade para implementar uma propriedade parametrizada. O assistente para adicionar propriedade implementa a propriedade adicionando um par de funções get/set que permitem ao usuário de controle acessar a propriedade usando a notação acima ou da maneira padrão.

Semelhante a métodos e propriedades, as propriedades parametrizadas também têm um limite para o número de parâmetros permitidos. No caso de propriedades parametrizadas, o limite é de 15 parâmetros (com um parâmetro reservado para armazenar o valor da propriedade).

O procedimento a seguir adiciona uma propriedade parametrizada, chamada array, que pode ser acessada como uma matriz bidimensional de inteiros.

#### <a name="to-add-a-parameterized-property-using-the-add-property-wizard"></a>Para adicionar uma propriedade com parâmetros usando o assistente para adicionar propriedade

1. Carregue o projeto do seu controle.

1. Em Modo de Exibição de Classe, expanda o nó biblioteca do seu controle.

1. Clique com o botão direito do mouse no nó da interface do seu controle (o segundo nó do nó da biblioteca) para abrir o menu de atalho.

1. No menu de atalho, clique em **Adicionar** e, em seguida, clique em **Adicionar Propriedade**.

1. Na caixa **nome da propriedade** , digite `Array` .

1. Na caixa **tipo de propriedade** , selecione **`short`** .

1. Para tipo de **implementação** , clique em **obter/definir métodos**.

1. Nas caixas **obter** função e **definir função** , digite nomes exclusivos para suas funções Get e Set ou aceite os nomes padrão.

1. Adicione um parâmetro, chamado *Row* (tipo *Short*), usando os controles de **nome de parâmetro** e **tipo de parâmetro** .

1. Adicione um segundo parâmetro chamado *coluna* (tipo *curto*).

1. Clique em **Concluir**.

### <a name="changes-made-by-the-add-property-wizard"></a>Alterações feitas pelo Assistente para adicionar propriedade

Quando você adiciona uma propriedade personalizada, o assistente para adicionar propriedade faz alterações no cabeçalho da classe de controle (. H) e a implementação (. CPP).

As linhas a seguir são adicionadas à classe Control. Arquivo H:

[!code-cpp[NVC_MFC_AxUI#35](codesnippet/cpp/mfc-activex-controls-advanced-topics_2.h)]

Esse código declara duas funções chamadas `GetArray` e `SetArray` que permitem que o usuário solicite uma linha e uma coluna específicas ao acessar a propriedade.

Além disso, o assistente para adicionar propriedade adiciona as seguintes linhas ao mapa de expedição de controle, localizado na implementação da classe de controle (. CPP) arquivo:

[!code-cpp[NVC_MFC_AxUI#36](codesnippet/cpp/mfc-activex-controls-advanced-topics_3.cpp)]

Por fim, as implementações `GetArray` das `SetArray` funções e são adicionadas ao final do. Arquivo CPP. Na maioria dos casos, você modificará a função Get para retornar o valor da propriedade. A função Set geralmente conterá o código que deve ser executado, antes ou depois da alteração da propriedade.

Para que essa propriedade seja útil, você pode declarar uma variável de membro de matriz bidimensional na classe de controle, do tipo **`short`** , para armazenar valores para a propriedade parametrizada. Em seguida, você poderia modificar a função Get para retornar o valor armazenado na linha e coluna adequadas, conforme indicado pelos parâmetros e modificar a função Set para atualizar o valor referenciado pelos parâmetros Row e Column.

## <a name="handling-errors-in-your-activex-control"></a><a name="_core_handling_errors_in_your_activex_control"></a>Tratamento de erros em seu controle ActiveX

Se as condições de erro ocorrerem no controle, talvez seja necessário reportar o erro para o contêiner de controle. Há dois métodos para relatar erros, dependendo da situação em que o erro ocorre. Se o erro ocorrer na função Get ou set de uma propriedade ou na implementação de um método de automação OLE, o controle deverá chamar [COleControl:: ThrowError](reference/colecontrol-class.md#throwerror), que sinaliza ao usuário de controle que ocorreu um erro. Se o erro ocorrer em qualquer outro momento, o controle deverá chamar [COleControl:: FireError](reference/colecontrol-class.md#fireerror), que dispara um evento de erro de estoque.

Para indicar o tipo de erro que ocorreu, o controle deve passar um código de erro para `ThrowError` ou `FireError` . Um código de erro é um código de status OLE, que tem um valor de 32 bits. Quando possível, escolha um código de erro do conjunto padrão de códigos definido no OLECTL. Arquivo de cabeçalho H. A tabela a seguir resume esses códigos.

### <a name="activex-control-error-codes"></a>Códigos de erro de controle ActiveX

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
|CTL_E_BADFILENAME|Nome de arquivo inadequado|
|CTL_E_TOOMANYFILES|Muitos arquivos|
|CTL_E_DEVICEUNAVAILABLE|Dispositivo não disponível|
|CTL_E_PERMISSIONDENIED|Permissão negada|
|CTL_E_DISKNOTREADY|O disco não está pronto|
|CTL_E_PATHFILEACCESSERROR|Erro de acesso ao caminho/arquivo|
|CTL_E_PATHNOTFOUND|demarcador não localizado|
|CTL_E_INVALIDPATTERNSTRING|Cadeia de caracteres de padrão inválida|
|CTL_E_INVALIDUSEOFNULL|Uso inválido de NULL|
|CTL_E_INVALIDFILEFORMAT|Formato de arquivo inválido|
|CTL_E_INVALIDPROPERTYVALUE|Valor de propriedade inválido|
|CTL_E_INVALIDPROPERTYARRAYINDEX|Índice de matriz de propriedade inválido|
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
|CTL_E_CANTSAVEFILETOTEMP|Não é possível salvar o arquivo em TEMP|
|CTL_E_SEARCHTEXTNOTFOUND|Texto de pesquisa não encontrado|
|CTL_E_REPLACEMENTSTOOLONG|Substituições muito longas|

Se necessário, use a macro CUSTOM_CTL_SCODE para definir um código de erro personalizado para uma condição que não seja coberta por um dos códigos padrão. O parâmetro para essa macro deve ser um inteiro entre 1000 e 32767, inclusive. Por exemplo:

[!code-cpp[NVC_MFC_AxUI#37](codesnippet/cpp/mfc-activex-controls-advanced-topics_4.cpp)]

Se você estiver criando um controle ActiveX para substituir um controle VBX existente, defina seus códigos de erro de controle ActiveX com os mesmos valores numéricos que o controle VBX usa para garantir que os códigos de erro sejam compatíveis.

## <a name="handling-special-keys-in-the-control"></a><a name="_core_handling_special_keys_in_your_control"></a>Manipulando chaves especiais no controle

Em alguns casos, talvez você queira lidar com certas combinações de teclas de forma especial; por exemplo, insira uma nova linha quando a tecla ENTER for pressionada em um controle de caixa de texto de várias linhas ou mova-se entre um grupo de controles de edição quando uma ID de chave direcional for pressionada.

Se a classe base do seu controle ActiveX for `COleControl` , você poderá substituir [CWnd::P retranslatemessage](reference/cwnd-class.md#pretranslatemessage) para tratar as mensagens antes de o contêiner processá-las. Ao usar essa técnica, sempre retornará **true** se você tratar a mensagem em sua substituição de `PreTranslateMessage` .

O exemplo de código a seguir demonstra uma possível maneira de lidar com qualquer mensagem relacionada às chaves direcionais.

[!code-cpp[NVC_MFC_AxUI#38](codesnippet/cpp/mfc-activex-controls-advanced-topics_5.cpp)]

Para obter mais informações sobre como manipular interfaces de teclado para um controle ActiveX, consulte a documentação do SDK do ActiveX.

## <a name="accessing-dialog-controls-that-are-invisible-at-run-time"></a><a name="_core_accessing_dialog_controls_that_are_invisible_at_run_time"></a>Acessando controles de caixa de diálogo que são invisíveis em tempo de execução

Você pode criar controles de caixa de diálogo que não têm interface do usuário e que estão invisíveis no tempo de execução. Se você adicionar um controle de ActiveX invisível no tempo de execução a uma caixa de diálogo e usar [CWnd:: GetDlgItem](reference/cwnd-class.md#getdlgitem) para acessar o controle, o controle não funcionará corretamente. Em vez disso, você deve usar uma das seguintes técnicas para obter um objeto que representa o controle:

- Usando o assistente para Adicionar variável de membro, selecione **variável de controle** e, em seguida, selecione a ID do controle. Insira um nome de variável de membro e selecione a classe wrapper do controle como o **tipo de controle**.

     -ou-

- Declare uma variável local e uma subclasse como o item de diálogo. Insira um código semelhante ao seguinte ( `CMyCtrl` é a classe wrapper, IDC_MYCTRL1 é a ID do controle):

   [!code-cpp[NVC_MFC_AxCont#19](codesnippet/cpp/mfc-activex-controls-advanced-topics_6.cpp)]

## <a name="see-also"></a>Confira também

[Controles ActiveX do MFC](mfc-activex-controls.md)
