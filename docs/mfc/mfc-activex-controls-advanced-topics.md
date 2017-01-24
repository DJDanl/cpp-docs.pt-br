---
title: "Controles ActiveX MFC: t&#243;picos avan&#231;ados | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método FireError"
  - "Controles ActiveX MFC, acessando controles de caixa de diálogo invisíveis"
  - "Controles ActiveX MFC, tópicos avançados"
  - "Controles ActiveX MFC, classes de banco de dados"
  - "Controles ActiveX MFC, códigos de erro"
  - "Controles ActiveX MFC, propriedade parametrizada"
  - "Controles ActiveX MFC, chaves especiais"
  - "Método PreTranslateMessage"
  - "Método ThrowError"
ms.assetid: e9e34abb-8e2d-461e-bb9c-a1aec5dcecbd
caps.latest.revision: 13
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Controles ActiveX MFC: t&#243;picos avan&#231;ados
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este artigo abrange os tópicos avançados relacionados a desenvolver controles ActiveX.  Eles incluem:  
  
-   [Usando classes base de dados do em controles ActiveX](#_core_using_database_classes_in_activex_controls)  
  
-   [Implementando uma propriedade com parâmetros](#_core_implementing_a_parameterized_property)  
  
-   [Tratar erros no controle ActiveX](#_core_handling_errors_in_your_activex_control)  
  
-   [Manipulando chaves especiais no controle](#_core_handling_special_keys_in_your_control)  
  
-   [Acessando os controles da caixa de diálogo que são invisíveis em tempo de execução](#_core_accessing_dialog_controls_that_are_invisible_at_run_time)  
  
##  <a name="_core_using_database_classes_in_activex_controls"></a> Usando classes base de dados do em controles ActiveX  
 Como as classes do controle ActiveX são parte da biblioteca de classe, você pode aplicar os mesmos procedimentos e regras para usar classes de base de dados em um aplicativo de MFC de padrão para desenvolver os controles ActiveX que usam as classes da base de dados de MFC.  
  
 Para obter uma visão geral das classes da base de dados de MFC, consulte [Classes de base de dados de MFC \(DAO e ODBC\)](../Topic/MFC%20Database%20Classes%20\(ODBC%20and%20DAO\).md).  O artigo apresenta as classes MFC ODBC e classes de MFC DAO e direciona você a obter mais detalhes sobre qualquer pessoa.  
  
> [!NOTE]
>  A partir do Visual C\+\+ .NET, o ambiente e os assistentes do Visual C\+\+ não dão suporte a DAO \(embora as classes de DAO são incluídas e você ainda pode usar o\).  A Microsoft recomenda que você use [Modelos OLE DB](../data/oledb/ole-db-programming.md) ou [ODBC e MFC](../data/odbc/odbc-and-mfc.md) para novos projetos.  Você só deve usar DAO manter os aplicativos existentes.  
  
##  <a name="_core_implementing_a_parameterized_property"></a> Implementando uma propriedade com parâmetros  
 Uma propriedade com parâmetros \(às vezes chamada de matriz de propriedade\) é um método para expor homogênea uma coleção de valores como uma única propriedade do controle.  Por exemplo, você pode usar uma propriedade com parâmetros para expor uma matriz ou um dicionário como uma propriedade.  No Visual Basic, essa propriedade é acessada usando a notação de matriz:  
  
 [!code-vb[NVC_MFC_AxVb#1](../mfc/codesnippet/VisualBasic/mfc-activex-controls-advanced-topics_1.vb)]  
  
 Use o assistente para adicionar a propriedade para implementar uma propriedade com parâmetros.  O assistente da propriedade adicionar implementa a propriedade adicionando um par de funções Get\/conjunto que permitem que o usuário de controle para acessar a propriedade usando notação acima ou na forma padrão.  
  
 Semelhante aos métodos e as propriedades, as propriedades com parâmetros também têm um limite para o número de parâmetros permitidos.  No caso de propriedades com parâmetros, o limite é 15 \(parâmetros com um parâmetro reservado para armazenar o valor da propriedade\).  
  
 O procedimento a seguir adiciona uma propriedade com parâmetros, chamada a matriz, que pode ser acessada como uma matriz bidimensional de valores inteiros.  
  
#### Para adicionar uma propriedade com parâmetros usando o assistente para adicionar propriedade  
  
1.  Carregar o projeto do controle.  
  
2.  Na exibição da classe, expanda o nó da biblioteca do controle.  
  
3.  Clique com o botão direito do mouse no nó da interface para o controle \(o segundo nó do nó da biblioteca\) para abrir o menu de atalho.  
  
4.  No menu de atalho, clique **Adicionar** e clique em **Adicionar Propriedade**.  
  
5.  Na caixa de **Nome da propriedade** , digite `Array`.  
  
6.  Na caixa de **Tipo de propriedade** , **short**selecione.  
  
7.  Para o tipo de **Implementação** , clique **Get\/Set Methods**.  
  
8.  Nas caixas de **Get Function** e de **Set Function** , os nomes exclusivos do seu e definem ou obtêm funções aceitam nomes padrão.  
  
9. Adicionar um parâmetro, `row` chamado \(tipo `short`\), usando os controles de **Nome do parâmetro** e de **Tipo de parâmetro** .  
  
10. Adicionar `column` chamado segundo parâmetro \(tipo `short`\).  
  
11. Clique em **Concluir**.  
  
### Alterações feitas pelo assistente para adicionar propriedade  
 Quando você adiciona uma propriedade personalizada, o assistente da propriedade adicionar fizer alterações no cabeçalho da classe de controle \(. H\) e os arquivos de implementação \(.CPP\).  
  
 As seguintes linhas são adicionadas à classe do controle. Arquivo de H:  
  
 [!code-cpp[NVC_MFC_AxUI#35](../mfc/codesnippet/CPP/mfc-activex-controls-advanced-topics_2.h)]  
  
 Esse código a seguir declara duas funções chamadas `GetArray` e `SetArray` que permitem ao usuário solicita uma linha e uma coluna específicas ao acessar a propriedade.  
  
 Além disso, o assistente da propriedade adicionar adiciona as seguintes linhas no mapa da expedição de controle, localizado no arquivo de implementação da classe de controle \(.CPP\):  
  
 [!code-cpp[NVC_MFC_AxUI#36](../mfc/codesnippet/CPP/mfc-activex-controls-advanced-topics_3.cpp)]  
  
 Finalmente, as implementações de `GetArray` e funções de `SetArray` são adicionadas ao final do arquivo de .CPP.  Na maioria dos casos, você modificará obter a função para retornar o valor da propriedade.  A função de conjunto geral conterá o código que deve executar, qualquer um antes ou depois da propriedade é alterado.  
  
 Para que essa propriedade é útil, você pode declarar uma variável de membro de matriz bidimensional na classe de controle, de tipo **short**, os valores das lojas da propriedade com parâmetros.  Você pode modificar a função obter para retornar o valor armazenado na linha e coluna apropriada, como indicado pelos parâmetros, e alterar a função de conjunto para atualizar o valor referenciado pelos parâmetros de linha e de coluna.  
  
##  <a name="_core_handling_errors_in_your_activex_control"></a> Tratar erros no controle ActiveX  
 Se as condições de erro ocorrerá em controle, talvez você precise informar o erro ao contêiner do controle.  Há dois métodos para reportar erros, dependendo da situação em que ocorreu o erro.  Se o erro ocorrer dentro de uma propriedade obtém ou define a função, ou na implementação de um método de Automação OLE, o controle deve chamar [COleControl::ThrowError](../Topic/COleControl::ThrowError.md), que sinaliza ao usuário de controle que ocorreu um erro.  Se o erro ocorrer em qualquer outro momento, o controle deve chamar [COleControl::FireError](../Topic/COleControl::FireError.md), que dispara um evento de erro de estoque.  
  
 Para indicar o tipo do erro ocorrido, o controle deve passar um código de erro a `ThrowError` ou a `FireError`.  Um código de erro é um código de status OLE, que tem um valor de 32 bits.  Quando possível, escolha um código de erro de conjunto padrão de código definidos no arquivo de cabeçalho de OLECTL.H.  A tabela a seguir resume esses códigos.  
  
### Códigos de erro do controle ActiveX  
  
|Erro|Descrição|  
|----------|---------------|  
|**CTL\_E\_ILLEGALFUNCTIONCALL**|Chamada de função ilegal|  
|**CTL\_E\_OVERFLOW**|Estouro|  
|**CTL\_E\_OUTOFMEMORY**|Memória insuficiente|  
|**CTL\_E\_DIVISIONBYZERO**|Divisão por zero|  
|**CTL\_E\_OUTOFSTRINGSPACE**|Sem espaço de cadeia de caracteres|  
|**CTL\_E\_OUTOFSTACKSPACE**|Sem espaço de pilha|  
|**CTL\_E\_BADFILENAMEORNUMBER**|Número ou nome de arquivo inválido|  
|**CTL\_E\_FILENOTFOUND**|Arquivo não encontrado|  
|**CTL\_E\_BADFILEMODE**|Modo Bad file|  
|**CTL\_E\_FILEALREADYOPEN**|Arquivo já está aberto|  
|**CTL\_E\_DEVICEIOERROR**|Erro de dispositivo de E\/S|  
|**CTL\_E\_FILEALREADYEXISTS**|O arquivo já existe|  
|**CTL\_E\_BADRECORDLENGTH**|Comprimento de registro inválido|  
|**CTL\_E\_DISKFULL**|Disco cheio|  
|**CTL\_E\_BADRECORDNUMBER**|Número de registro inválido.|  
|**CTL\_E\_BADFILENAME**|Nome de arquivo incorreto|  
|**CTL\_E\_TOOMANYFILES**|Há arquivos demais|  
|**CTL\_E\_DEVICEUNAVAILABLE**|Dispositivo não disponível|  
|**CTL\_E\_PERMISSIONDENIED**|Permissão negada|  
|**CTL\_E\_DISKNOTREADY**|Disco não está pronto|  
|**CTL\_E\_PATHFILEACCESSERROR**|Caminho\/erro de acesso a arquivos|  
|**CTL\_E\_PATHNOTFOUND**|Caminho não encontrado|  
|**CTL\_E\_INVALIDPATTERNSTRING**|Cadeia de caracteres inválido de padrão|  
|**CTL\_E\_INVALIDUSEOFNULL**|Uso inválido de NULL|  
|**CTL\_E\_INVALIDFILEFORMAT**|Formato de arquivo inválido|  
|**CTL\_E\_INVALIDPROPERTYVALUE**|Valor de propriedade inválido|  
|**CTL\_E\_INVALIDPROPERTYARRAYINDEX**|Índice da matriz de propriedade inválido|  
|**CTL\_E\_SETNOTSUPPORTEDATRUNTIME**|Conjunto não tem suporte em tempo de execução|  
|**CTL\_E\_SETNOTSUPPORTED**|Definições não suportadas \(propriedade somente leitura\)|  
|**CTL\_E\_NEEDPROPERTYARRAYINDEX**|Índice de matriz de propriedade necessário|  
|**CTL\_E\_SETNOTPERMITTED**|Conjunto não permitido|  
|**CTL\_E\_GETNOTSUPPORTEDATRUNTIME**|Obter não tem suporte em tempo de execução|  
|**CTL\_E\_GETNOTSUPPORTED**|Obter não tem suporte \(a propriedade somente gravação\)|  
|**CTL\_E\_PROPERTYNOTFOUND**|Propriedade não encontrada|  
|**CTL\_E\_INVALIDCLIPBOARDFORMAT**|Formato inválido da área de transferência|  
|**CTL\_E\_INVALIDPICTURE**|Imagem inválido|  
|**CTL\_E\_PRINTERERROR**|Erro com a Impressora|  
|**CTL\_E\_CANTSAVEFILETOTEMP**|Não é possível salvar o arquivo na temperatura|  
|**CTL\_E\_SEARCHTEXTNOTFOUND**|Texto de pesquisa não encontrado|  
|**CTL\_E\_REPLACEMENTSTOOLONG**|Substituições muito longas|  
  
 Se necessário, use a macro de **CUSTOM\_CTL\_SCODE** para definir um código de erro personalizada para uma condição que não é coberta por um dos códigos padrão.  O parâmetro para esta macro deve ser um inteiro entre 1000 e 32767, inclusive.  Por exemplo:  
  
 [!code-cpp[NVC_MFC_AxUI#37](../mfc/codesnippet/CPP/mfc-activex-controls-advanced-topics_4.cpp)]  
  
 Se você estiver criando um controle ActiveX para substituir um controle existente de VBX, defina os códigos de erro do controle ActiveX com os mesmos valores numéricos que o controle de VBX usa para garantir que os códigos de erro sejam compatíveis.  
  
##  <a name="_core_handling_special_keys_in_your_control"></a> Manipulando chaves especiais no controle  
 Em alguns casos você queira tratar determinadas combinações de teclas em uma forma especial; por exemplo, insira uma nova linha quando a tecla ENTER é pressionada em um controle ou em um movimentação multilinha da caixa de texto entre um grupo de controles de edição quando um ID chave direcional pressionou.  
  
 Se a classe base de seu controle ActiveX é `COleControl`, você pode substituir [CWnd::PreTranslateMessage](../Topic/CWnd::PreTranslateMessage.md) para tratar mensagens antes que o contêiner as processada.  Ao usar essa técnica, **Verdadeiro** de retorno sempre se você trata a mensagem na substituição de `PreTranslateMessage`.  
  
 O exemplo de código a seguir demonstra uma maneira possível de tratar todas as mensagens relacionadas às chaves direcionais.  
  
 [!code-cpp[NVC_MFC_AxUI#38](../mfc/codesnippet/CPP/mfc-activex-controls-advanced-topics_5.cpp)]  
  
 Para obter mais informações sobre o teclado de manipulação interfaces para um controle ActiveX, consulte a documentação do SDK do ActiveX.  
  
##  <a name="_core_accessing_dialog_controls_that_are_invisible_at_run_time"></a> Acessando os controles da caixa de diálogo que são invisíveis em tempo de execução  
 Você pode criar os controles da caixa de diálogo que não têm nenhuma interface do usuário e são invisíveis em tempo de execução.  Se você adicionar em tempo de execução um controle ActiveX invisível em uma caixa de diálogo e usa [CWnd::GetDlgItem](../Topic/CWnd::GetDlgItem.md) para acessar o controle, o controle não funcionará corretamente.  Em vez disso, você deve usar uma das seguintes técnicas para obter um objeto que representa o controle:  
  
-   Usando o assistente variável de membro adicionar **Control Variable** , selecione e selecione a ID de controle  Digite um nome de variável de membro e selecione a classe de invólucro de controle como **Tipo de controle**.  
  
     \- ou \-  
  
-   Declare uma variável local e uma subclasse como o item da caixa de diálogo.  Inserir o código que se assemelha ao seguinte \(`CMyCtrl` é a classe de invólucro, `IDC_MYCTRL1` é a ID do controle\):  
  
     [!code-cpp[NVC_MFC_AxCont#19](../mfc/codesnippet/CPP/mfc-activex-controls-advanced-topics_6.cpp)]  
  
## Consulte também  
 [Controles ActiveX MFC](../mfc/mfc-activex-controls.md)