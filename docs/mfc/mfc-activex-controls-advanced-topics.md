---
title: 'Controles ActiveX MFC: Tópicos avançados | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 99480a8d77aef1822034be100a03f73cfa9d1be0
ms.sourcegitcommit: 060f381fe0807107ec26c18b46d3fcb859d8d2e7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/25/2018
ms.locfileid: "36929998"
---
# <a name="mfc-activex-controls-advanced-topics"></a>Controles ActiveX MFC: tópicos avançados
Este artigo aborda tópicos avançados relacionados ao desenvolvimento de controles ActiveX. Elas incluem:  
  
-   [Usando Classes de banco de dados em controles ActiveX](#_core_using_database_classes_in_activex_controls)  
  
-   [Implementando uma propriedade com parâmetros](#_core_implementing_a_parameterized_property)  
  
-   [Tratamento de erros no seu controle ActiveX](#_core_handling_errors_in_your_activex_control)  
  
-   [Manipulação de chaves especiais no controle](#_core_handling_special_keys_in_your_control)  
  
-   [Acessando controles de caixa de diálogo que são visíveis em tempo de execução](#_core_accessing_dialog_controls_that_are_invisible_at_run_time)  
  
##  <a name="_core_using_database_classes_in_activex_controls"></a> Usando Classes de banco de dados em controles ActiveX  
 Como as classes de controle ActiveX fazem parte da biblioteca de classes, você pode aplicar os mesmos procedimentos e regras para usar classes de banco de dados em um aplicativo MFC padrão para o desenvolvimento de controles ActiveX que usam as classes de banco de dados MFC.  
  
 Para obter uma visão geral das classes de banco de dados MFC, consulte [Classes de banco de dados MFC (DAO e ODBC)](../data/mfc-database-classes-odbc-and-dao.md). O artigo apresenta as classes MFC ODBC e MFC DAO classes e direciona você para obter mais detalhes sobre qualquer um.  
  
> [!NOTE]
>  Os assistentes e o ambiente do Visual C++ não dão suporte DAO (embora as classes DAO estão incluídas e você ainda pode usá-los). A Microsoft recomenda que você use [modelos OLE DB](../data/oledb/ole-db-programming.md) ou [ODBC e MFC](../data/odbc/odbc-and-mfc.md) para novos projetos. Você só deve usar DAO na manutenção de aplicativos existentes.  
  
##  <a name="_core_implementing_a_parameterized_property"></a> Implementando uma propriedade com parâmetros  
 Uma propriedade com parâmetros (às vezes chamada de uma matriz de propriedade) é um método para expor uma coleção homogênea de valores como uma única propriedade do controle. Por exemplo, você pode usar uma propriedade com parâmetros para expor um dicionário como uma propriedade ou uma matriz. No Visual Basic, essa propriedade é acessada usando a notação de matriz:  
  
 [!code-vb[NVC_MFC_AxVb#1](../mfc/codesnippet/visualbasic/mfc-activex-controls-advanced-topics_1.vb)]  
  
 Use o Assistente para adicionar propriedade para implementar uma propriedade com parâmetros. O Assistente para adicionar propriedade implementa a propriedade adicionando um par de funções de Get/Set que permitem que o usuário controle acessar a propriedade usando a notação acima ou da maneira padrão.  
  
 Semelhante aos métodos e propriedades, propriedades parametrizadas também têm um limite para o número de parâmetros permitido. No caso de propriedades com parâmetros, o limite é de 15 parâmetros (com um parâmetro reservado para armazenar o valor da propriedade).  
  
 O procedimento a seguir adiciona uma propriedade com parâmetros, chamada de matriz, que pode ser acessado como uma matriz bidimensional de números inteiros.  
  
#### <a name="to-add-a-parameterized-property-using-the-add-property-wizard"></a>Para adicionar uma propriedade com parâmetros usando o Assistente para adicionar propriedade  
  
1.  Carregar projeto do controle.  
  
2.  No modo de exibição de classe, expanda o nó de biblioteca de seu controle.  
  
3.  Para abrir o menu de atalho, clique com botão direito no nó de interface de seu controle (o segundo nó do nó de biblioteca).  
  
4.  No menu de atalho, clique em **adicionar** e, em seguida, clique em **adicionar propriedade**.  
  
5.  No **nome da propriedade** , digite `Array`.  
  
6.  No **tipo de propriedade** selecione **curto**.  
  
7.  Para **implementação** tipo, clique em **métodos Get/Set**.  
  
8.  No **obter função** e **função Set** caixas, digite os nomes exclusivos para o Get e definir funções ou aceite os nomes padrão.  
  
9. Adicionar um parâmetro chamado *linha* (tipo *curto*) usando o **nome do parâmetro** e **tipo de parâmetro** controles.  
  
10. Adicionar um segundo parâmetro chamado *coluna* (tipo *curto*).  
  
11. Clique em **Finalizar**.  
  
### <a name="changes-made-by-the-add-property-wizard"></a>As alterações feitas o Assistente para adicionar propriedade  
 Quando você adiciona uma propriedade personalizada, o Assistente para adicionar propriedade faz alterações para o cabeçalho de classe de controle (. H) e a implementação (. Arquivos CPP).  
  
 As linhas a seguir são adicionadas à classe do controle. Arquivo H:  
  
 [!code-cpp[NVC_MFC_AxUI#35](../mfc/codesnippet/cpp/mfc-activex-controls-advanced-topics_2.h)]  
  
 Esse código declara duas funções chamadas `GetArray` e `SetArray` que permitem que o usuário solicitar uma linha e coluna específica ao acessar a propriedade.  
  
 Além disso, o Assistente para adicionar propriedade adiciona as seguintes linhas ao mapa de expedição do controle, na implementação de classe de controle (. Arquivo CPP):  
  
 [!code-cpp[NVC_MFC_AxUI#36](../mfc/codesnippet/cpp/mfc-activex-controls-advanced-topics_3.cpp)]  
  
 Por fim, as implementações do `GetArray` e `SetArray` funções são adicionadas ao final da. Arquivo CPP. Na maioria dos casos, você modificará a função Get para retornar o valor da propriedade. A função de conjunto geralmente conterá um código que deve executar antes ou após as alterações de propriedade.  
  
 Para esta propriedade ser útil, você pode declarar uma variável de membro de matriz bidimensional na classe de controle do tipo **curto**, para armazenar os valores para a propriedade com parâmetros. Você pode modificar a função Get para retornar o valor armazenado na linha apropriada e coluna, conforme indicado pelos parâmetros e modifique a função de conjunto para atualizar o valor referenciado pelos parâmetros de linha e coluna.  
  
##  <a name="_core_handling_errors_in_your_activex_control"></a> Tratamento de erros no seu controle ActiveX  
 Se ocorrerem condições de erro no controle, você precisará relatar o erro para o contêiner de controle. Há dois métodos para relatório de erros, dependendo da situação em que o erro ocorre. Se o erro ocorrer dentro de uma propriedade Get ou Set função, ou na implementação de um método de automação OLE, o controle deve chamar [COleControl::ThrowError](../mfc/reference/colecontrol-class.md#throwerror), qual sinaliza que o usuário do controle que ocorreu um erro. Se o erro ocorrer a qualquer momento, o controle deve chamar [COleControl::FireError](../mfc/reference/colecontrol-class.md#fireerror), que dispara um evento de erro de estoque.  
  
 Para indicar o tipo de erro que ocorreu, o controle deve passar um código de erro para `ThrowError` ou `FireError`. Um código de erro é um código de status OLE, que tem um valor de 32 bits. Quando possível, escolha um código de erro do conjunto padrão de códigos definidos no OLECTL. Arquivo de cabeçalho de H. A tabela a seguir resume esses códigos.  
  
### <a name="activex-control-error-codes"></a>Códigos de erro de controle ActiveX  
  
|Erro|Descrição|  
|-----------|-----------------|  
|CTL_E_ILLEGALFUNCTIONCALL|Chamada de função ilegal|  
|CTL_E_OVERFLOW|Estouro|  
|CTL_E_OUTOFMEMORY|Memória insuficiente|  
|CTL_E_DIVISIONBYZERO|Divisão por zero|  
|CTL_E_OUTOFSTRINGSPACE|Sem espaço de cadeia de caracteres|  
|CTL_E_OUTOFSTACKSPACE|Espaço de pilha|  
|CTL_E_BADFILENAMEORNUMBER|Nome ou número de arquivo inválido|  
|CTL_E_FILENOTFOUND|Arquivo não encontrado|  
|CTL_E_BADFILEMODE|Modo de arquivo inválido|  
|CTL_E_FILEALREADYOPEN|Arquivo já aberto|  
|CTL_E_DEVICEIOERROR|Erro de E/S do dispositivo|  
|CTL_E_FILEALREADYEXISTS|O arquivo já existe|  
|CTL_E_BADRECORDLENGTH|Comprimento de registro inválido|  
|CTL_E_DISKFULL|Disco cheio|  
|CTL_E_BADRECORDNUMBER|Número de registro incorreto|  
|CTL_E_BADFILENAME|Nome de arquivo inválido|  
|CTL_E_TOOMANYFILES|Muitos arquivos|  
|CTL_E_DEVICEUNAVAILABLE|Dispositivo não disponível|  
|CTL_E_PERMISSIONDENIED|Permissão negada|  
|CTL_E_DISKNOTREADY|Disco não está pronto|  
|CTL_E_PATHFILEACCESSERROR|Erro de acesso caminho/arquivo|  
|CTL_E_PATHNOTFOUND|demarcador não localizado|  
|CTL_E_INVALIDPATTERNSTRING|Cadeia de caracteres de padrão inválido|  
|CTL_E_INVALIDUSEOFNULL|Uso inválido de NULL|  
|CTL_E_INVALIDFILEFORMAT|Formato de arquivo inválido|  
|CTL_E_INVALIDPROPERTYVALUE|Valor de propriedade inválido|  
|CTL_E_INVALIDPROPERTYARRAYINDEX|Índice de matriz de propriedade inválido|  
|CTL_E_SETNOTSUPPORTEDATRUNTIME|Conjunto não tem suportado em tempo de execução|  
|CTL_E_SETNOTSUPPORTED|Definições não suportadas (propriedade somente leitura)|  
|CTL_E_NEEDPROPERTYARRAYINDEX|Índice da matriz de propriedade necessário|  
|CTL_E_SETNOTPERMITTED|Set não permitido|  
|CTL_E_GETNOTSUPPORTEDATRUNTIME|Obter não tem suporte em tempo de execução|  
|CTL_E_GETNOTSUPPORTED|Obter sem suporte (propriedade de somente gravação)|  
|CTL_E_PROPERTYNOTFOUND|Propriedade não localizada|  
|CTL_E_INVALIDCLIPBOARDFORMAT|Formato inválido de área de transferência|  
|CTL_E_INVALIDPICTURE|Imagem inválida|  
|CTL_E_PRINTERERROR|Erro de impressora|  
|CTL_E_CANTSAVEFILETOTEMP|Não é possível salvar o arquivo no diretório TEMP|  
|CTL_E_SEARCHTEXTNOTFOUND|Texto de pesquisa não encontrado|  
|CTL_E_REPLACEMENTSTOOLONG|Substituições muito longos|  
  
 Se necessário, use a macro CUSTOM_CTL_SCODE para definir um código de erro personalizado para uma condição que não é coberto por um dos códigos de padrão. O parâmetro para esta macro deve ser um inteiro entre 1000 e 32767, inclusive. Por exemplo:  
  
 [!code-cpp[NVC_MFC_AxUI#37](../mfc/codesnippet/cpp/mfc-activex-controls-advanced-topics_4.cpp)]  
  
 Se você estiver criando um controle ActiveX para substituir um controle VBX existente, defina os códigos de erro do controle ActiveX com os mesmos valores numéricos, que o controle VBX usa para garantir que os códigos de erro são compatíveis.  
  
##  <a name="_core_handling_special_keys_in_your_control"></a> Manipulação de chaves especiais no controle  
 Em alguns casos você talvez queira tratar algumas combinações de pressionamento de tecla de maneira especial; Por exemplo, inserir uma nova linha quando a tecla ENTER é pressionada no texto de várias linhas controle de caixa ou mover entre um grupo de edição controla quando um direcional pressionado de ID de chave.  
  
 Se a classe base do controle ActiveX é `COleControl`, você pode substituir [CWnd::PreTranslateMessage](../mfc/reference/cwnd-class.md#pretranslatemessage) para lidar com mensagens antes do contêiner processá-las. Ao usar essa técnica, sempre retornará **TRUE** se manipular a mensagem em sua substituição de `PreTranslateMessage`.  
  
 O exemplo de código a seguir demonstra uma maneira possível de lidar com todas as mensagens relacionadas às chaves direcionais.  
  
 [!code-cpp[NVC_MFC_AxUI#38](../mfc/codesnippet/cpp/mfc-activex-controls-advanced-topics_5.cpp)]  
  
 Para obter mais informações sobre como tratar as interfaces de teclado para um controle ActiveX, consulte a documentação do SDK do ActiveX.  
  
##  <a name="_core_accessing_dialog_controls_that_are_invisible_at_run_time"></a> Acessando controles de caixa de diálogo que são visíveis em tempo de execução  
 Você pode criar controles de caixa de diálogo que não tem nenhuma interface do usuário e são visíveis em tempo de execução. Se você adicionar um invisível em tempo de execução controle ActiveX a uma caixa de diálogo e use [CWnd::GetDlgItem](../mfc/reference/cwnd-class.md#getdlgitem) para o controle de acesso, o controle não funcionará corretamente. Em vez disso, você deve usar uma das seguintes técnicas para obter um objeto que representa o controle:  
  
-   Usando o Assistente de adição membro variável, selecione **controle variável** e, em seguida, selecione a identificação. do controle Insira um nome de variável de membro e selecione a classe de wrapper do controle como o **tipo de controle**.  
  
     -ou-  
  
-   Declare uma variável local e da subclasse como o item de caixa de diálogo. Inserir código semelhante ao seguinte (`CMyCtrl` é a classe de invólucro, IDC_MYCTRL1 é a identificação do controle):  
  
     [!code-cpp[NVC_MFC_AxCont#19](../mfc/codesnippet/cpp/mfc-activex-controls-advanced-topics_6.cpp)]  
  
## <a name="see-also"></a>Consulte também  
 [Controles ActiveX do MFC](../mfc/mfc-activex-controls.md)

