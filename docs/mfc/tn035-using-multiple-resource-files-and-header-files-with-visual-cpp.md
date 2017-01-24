---
title: "TN035: usando v&#225;rios arquivos de recurso e arquivos de cabe&#231;alho com o Visual C++ | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "vc.resources"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "arquivos de recursos, várias"
  - "TN035"
ms.assetid: 1f08ce5e-a912-44cc-ac56-7dd93ad73fb6
caps.latest.revision: 13
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# TN035: usando v&#225;rios arquivos de recurso e arquivos de cabe&#231;alho com o Visual C++
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

> [!NOTE]
>  A nota técnica a seguir não foi atualizada desde que ela foi incluída pela primeira vez na documentação online.  Como resultado, alguns procedimentos e tópicos podem estar incorretos ou expirados.  Para obter as informações mais recentes, é recomendável que você procure o tópico de interesse no índice de documentação online.  
  
 Essa observação descreve como arquivos de recurso de suporte do editor de recursos do Visual C\+\+ vários e arquivos de cabeçalho compartilhados em um único projeto ou compartilhados por vários projetos e como você pode aproveitar desse suporte.  Essa observação responde a essas questões:  
  
-   Quando você quiser dividir um projeto em vários arquivos de recurso e\/ou em arquivos de cabeçalho; como você faz isso?  
  
-   Como você compartilha um arquivo de cabeçalho comum .H entre dois arquivos .RC?  
  
-   Como você divide os recursos de projeto em vários arquivos .RC?  
  
-   Como você \(e ferramentas\) gerencia as dependências de compilação entre os arquivos .RC, .CPP, e .H?  
  
 Você deve estar ciente de que se adicionar um arquivo de recursos adicional ao projeto, o ClassWizard não reconhecerá os recursos no arquivo adicionado.  
  
 Essa observação está estruturada para responder perguntas anterior como segue:  
  
-   **Overview of How Visual C\+\+ Manages Resource Files and Header Files** fornece uma visão geral de como o comando Resource Set Includes no Visual C\+\+ permite que você use vários arquivos de recurso e arquivos de cabeçalho no mesmo projeto.  
  
-   **Analysis of AppWizard\-created .RC and .H Files** tem vários arquivos de recurso e arquivos de cabeçalho que são usados por um aplicativo criado por AppWizard.  Esses arquivos servem como um bom modelo para arquivos de recurso adicional e os arquivos de cabeçalho que você deseja adicionar ao seu projeto.  
  
-   **Including Additional Header Files** descreve onde você pode desejar incluir vários arquivos de cabeçalho, e fornece detalhes sobre como fazer isso.  
  
-   **Sharing a Header File Between Two .RC Files** mostra como você pode compartilhar um arquivo de cabeçalho entre vários arquivos de .RC em projetos diferentes ou no mesmo projeto.  
  
-   **Using Multiple Resource Files in the Same Project** descreve onde você pode desejar dividir seu projeto em vários arquivos .RC e fornece os detalhes sobre como fazer isso.  
  
-   **Enforcement of Non\-Editable Visual C\+\+ Files** descreve como você pode certificar\-se de que o Visual C\+\+ não edite e reformate inadvertidamente um recurso personalizado.  
  
-   **Managing Symbols Shared by Multiple Visual C\+\+\-Edited .RC Files** descreve como compartilhar os mesmos símbolos em vários arquivos .RC e como evitar atribuir valores numéricos de ID duplicada.  
  
-   **Managing Dependencies Between .RC, .CPP, and .H Files** descreve como o Visual C\+\+ impede a recompilação desnecessária de arquivos .CPP que são dependentes de arquivos de símbolo de recurso.  
  
-   **How Visual C\+\+ Manages Set Includes Information** fornece detalhes técnicos sobre como o Visual C\+\+ mantém o monitoramento de vários arquivos \(aninhados\) .RC e de vários arquivos de cabeçalho que são incluídos por um arquivo .RC.  
  
 **Visão geral de como o Visual C\+\+ gerencia os arquivos de recurso e os arquivos de cabeçalho**  
  
 Visual C\+\+ gerencia um único arquivo de recurso de .RC e um arquivo de cabeçalho .H como um par acoplado de arquivos.  Quando você edita e salva os recursos em um arquivo .RC, os símbolos são editados e salvos indiretamente no arquivo .H correspondente.  Embora você possa abrir e editar vários arquivos .RC por vez \(usando a interface do usuário MDI do Visual C\+\+\) para qualquer arquivo .RC dado, você edita, de forma indireta, exatamente um arquivo de cabeçalho correspondente.  
  
 **Arquivo de Cabeçalho do Símbolo**  
  
 Por padrão, o Visual C\+\+ nomeia sempre o arquivo de cabeçalho correspondente RESOURCE.H, independentemente do nome do arquivo de recurso \(por exemplo, MYAPP.RC\).  Usando o comando **Recurso Inclui** de menu **Modo de Visualização** no Visual C\+\+, você pode alterar o nome deste arquivo de cabeçalho atualizando o arquivo do cabeçalho na caixa de diálogo **Conjunto Inclui**.  
  
 **Diretivas do símbolo somente leitura**  
  
 Embora o Visual C\+\+ edite apenas um arquivo de cabeçalho para qualquer arquivo .RC dado, o Visual C\+\+ oferece suporte à referências aos símbolos definidos em arquivos de cabeçalho somente leitura.  Usando o comando **Recurso inclui** de menu de **Modo de Visualização** no Visual C\+\+, você pode especificar qualquer número de arquivos adicionais somente para leitura como as Diretivas de Símbolos somente leitura.  A restrição “somente leitura” significa que quando você adiciona um novo recurso no arquivo de .RC, você pode usar um símbolo definido no arquivo de cabeçalho somente leitura; mas se você excluir o recurso, o símbolo ainda permanece definido no arquivo de cabeçalho somente leitura.  Não é possível alterar o valor numérico atribuído a um símbolo somente leitura.  
  
 **Diretivas de tempo de compilação**  
  
 Visual C\+\+ também suporta aninhamento de arquivos de recursos, onde um arquivo de .RC é \#incluído em outro.  Quando você edita um arquivo .RC com o Visual C\+\+, todos os recursos nos arquivos \#include'd não ficarão visíveis.  Mas quando você compila o arquivo .RC, os arquivos de \#include também são compilados.  Usando o comando **Recurso inclui** de menu de **Modo de Visualização** Visual C\+\+, você pode especificar qualquer número de arquivos \#include .RC como Políticas de Tempo de Compilação.  
  
 Observe o que acontece se você ler no Visual C\+\+ um arquivo .RC que inclua outro arquivo .RC que *não* é especificado como uma diretiva de compilação.  Esta situação pode ocorrer quando você faz para Visual C\+\+ um arquivo de .RC que você mantivesse anteriormente manualmente com um editor de texto.  Quando o Visual C\+\+ lê o arquivo .RC \#include'd, ele mescla os recursos de \#include'd no arquivo .RC pai.  Quando você salva o arquivo .RC pai, na verdade, a instrução de \#include é substituída pelos recursos \#include'd.  Se você não desejar que esta mesclagem ocorra, é necessário remover a instrução de \#include do arquivo .RC pai *antes* da leitura no Visual C\+\+; em seguida, usando o Visual C\+\+, adicione novamente a mesma instrução de \#include que uma diretiva de compilação.  
  
 O Visual C\+\+ salva em um arquivo .RC os três tipos definidos acima do conjunto que incluem informações \(Arquivo de cabeçalho do símbolo, Diretivas de símbolo somente leitura e Políticas de tempo de compilação\) nas diretivas de \#include *e* nos recursos de TEXTINCLUDE.  Os recursos de TEXTINCLUDE, um detalhe de implementação que você não precise normalmente de tratar, são explicados em [Como Visual C\+\+ gerencia as informações de definições do Set](#_mfcnotes_tn035_set_includes).  
  
 **Análise dos arquivos .RC e .H criados por AppWizard**  
  
 Examinar o código do aplicativo gerado por AppWizard fornece informações sobre como o Visual C\+\+ gerencia vários arquivos de recurso e arquivos de cabeçalho.  Os trechos de código são examinados abaixo são de um aplicativo de MYAPP gerado pelo AppWizard as opções padrão.  
  
 Um aplicativo criado por AppWizard usa vários arquivos de recurso e vários arquivos de cabeçalho, conforme resumido no diagrama a seguir:  
  
```  
RESOURCE.H     AFXRES.H                      
       \       /                                
        \     /                                  
       MYAPP.RC                                 
           |                                  
           |                                
     RES\MYAPP.RC2    
     AFXRES.RC                     
     AFXPRINT.RC                   
```  
  
 É possível exibir essas relações de vários arquivos usando o comando Arquivo do Visual C\+\+\/O Conjunto Inclui.  
  
 MYAPP.RC  
 O arquivo de recurso do aplicativo que você edita usando o Visual C\+\+.  
  
 RESOURCE.H é o arquivo de cabeçalho específico do aplicativo.  É sempre denominado RESOURCE.H por AppWizard, consistente com a nomeação padrão do Visual C\+\+ do arquivo de cabeçalho.  O \#include para este arquivo de cabeçalho é a primeira instrução no arquivo de recurso \(MYAPP.RC\):  
  
```  
//Microsoft Visual C++ generated resource script  
//  
#include "resource.h"  
```  
  
 RES\\MYAPP.RC2  
 Contém os recursos que não serão editados pelo Visual C\+\+, mas que serão incluídos no arquivo .exe compilado final.  O AppWizard não cria nenhum recurso do gênero por padrão, uma vez que o Visual C\+\+ pode editar todos os recursos padrão, incluindo o recurso de versão \(um novo recurso nesta versão.\)  Um arquivo vazio é gerado por AppWizard caso que você deseje adicionar seus próprios recursos formatados e personalizados ao arquivo.  
  
 Se você usar recursos formatados personalizados, será possível adicioná\-los a RES\\MYAPP.RC2 e editá\-los usando o editor de texto do Visual C\+\+.  
  
 AFXRES.RC e AFXPRINT.RC contêm os recursos padrão requeridos por determinados recursos da estrutura.  Como o RES\\MYAPP.RC2, esses dois arquivos de recurso fornecidos por estrutura são incluídos com \#include no final de MYAPP.RC, e são especificados na caixa de diálogo Políticas de tempo de compilação do conjunto Include.  Portanto, você não diretamente exibe ou não editar esses recursos de estrutura quando você editar MYAPP.RC Visual C\+\+, mas são compilados no arquivo .exe de binário .RES do arquivo e o final.  Para obter mais informações sobre recursos padrão do framework, incluindo procedimentos para modificá\-los, consulte [Observação técnica 23](../mfc/tn023-standard-mfc-resources.md).  
  
 AFXRES.H define símbolos padrão, como `ID_FILE_NEW`, usados pela estrutura e usados especificamente no AFXRES.RC.  AFXRES.H também inclui WINRES.H, que contém um subconjunto de WINDOWS.H que é requerido pelos arquivos .RC gerados pelo Visual C\+\+, bem como AFXRES.RC.  Os símbolos definidos em AFXRES.H estão disponíveis conforma você edita o arquivo do recurso do aplicativo \(MYAPP.RC\).  Por exemplo, `ID_FILE_NEW` é usado para o novo item do menu Arquivo no recurso do menu de MYAPP.RC.  Não é possível modificar ou excluir esses símbolos definidos pelo framework.  
  
 **Incluindo arquivos de cabeçalho adicionais**  
  
 O aplicativo criado com o AppWizard inclui apenas dois arquivos de cabeçalho: RESOURCE.H e AFXRES.H.  Somente RESOURCE.H é específico do aplicativo.  Pode ser necessário incluir arquivos de cabeçalho somente leitura adicionais nos seguintes casos:  
  
 O arquivo de cabeçalho é fornecido por uma fonte externa, ou você deseja compartilhar o arquivo de cabeçalho entre vários projetos ou várias partes do mesmo projeto.  
  
 O arquivo de cabeçalho tem a formatação e os comentários que você não gostaria que o Visual C\+\+ alterasse ou filtrasse ao salvar o arquivo.  Por exemplo, você pode querer preservar \#defines que usam a aritmética simbólica, como:  
  
```  
#define RED 0  
#define BLUE 1  
#define GREEN 2  
#define ID_COLOR_BUTTON 1001  
#define ID_RED_BUTTON (ID_COLOR_BUTTON + RED)  
#define ID_BLUE_BUTTON (ID_COLOR_BUTTON + BLUE)  
#define ID_GREEN_BUTTON (ID_COLOR_BUTTON + GREEN)  
```  
  
 É possível incluir arquivos de cabeçalho somente leitura adicionais usando o comando **O Recurso Inclui** para especificar a instrução \#include como segunda Diretiva Somente Leitura do Símbolo, como:  
  
```  
#include "afxres.h"  
#include "second.h"  
```  
  
 O novo diagrama de relação do arquivo tem esta aparência:  
  
```  
               AFXRES.H         
RESOURCE.H     SECOND.H                      
      \       /                                
       \     /                                  
      MYAPP.RC     
          |                                  
          |                                
    RES\MYAPP.RC2    
    AFXRES.RC                     
    AFXPRINT.RC                   
```  
  
 **Compartilhando um Arquivo de cabeçalho entre dois arquivos .RC**  
  
 Você pode desejar compartilhar um arquivo de cabeçalho entre dois arquivos .RC que estão em diferentes projetos ou, possivelmente, no mesmo projeto.  Para fazer isso, aplique somente a técnica somente leitura das diretivas descrita acima para ambos os arquivos .RC.  Em casos onde os dois arquivos .RC são de aplicativos diferentes \(projetos diferentes\), o resultado é ilustrado no diagrama a seguir:  
  
```  
     RESOURCE.H   AFXRES.H   RESOURCE.H    
    (for MYAPP1)  SECOND.H   (for MYAPP2)               
          \       /     \       /             
           \     /       \     /               
          MYAPP1.RC      MYAPP2.RC                   
           /    \        /     \                     
          /      \      /       \              
RES\MYAPP1.RC2  AFXRES.RC     RES\MYAPP2.RC2                
                AFXPRINT.RC                   
```  
  
 O caso em que o segundo arquivo do cabeçalho é compartilhado por dois arquivos .RC no mesmo aplicativo \(projeto\) é discutido abaixo.  
  
 **Usando vários arquivos de recurso no mesmo Projeto**  
  
 Visual C\+\+ e o Compilador de Recursos dão suporte a vários arquivos .RC no mesmo projeto nas \#inclusões de um arquivo .RC em outro.  O aninhamento múltiplo é permitido.  Há várias razões para dividir os recursos de seus projetos em vários arquivos .RC:  
  
-   É mais fácil gerenciar um grande número de recursos entre vários membros da equipe de projeto se você dividir os recursos em vários arquivos .RC.  Se você usar um pacote de gerenciamento de controle de origem para fazer o check\-out de arquivos e fazer o check\-in de alterações, dividir os recursos em vários arquivos .RC fornecerá um melhor controle sobre como gerenciar alterações aos recursos.  
  
-   Se você desejar usar políticas de pré\-processamento, como \#ifdef, \#endif, e \#define, para as partes de seus recursos, você deve isolá\-las em recursos somente leitura que serão compilados pelo compilador de recurso.  
  
-   Os arquivos .RC de componentes são carregados e salvos mais rapidamente no Visual C\+\+ do que um arquivo .RC composto.  
  
-   Se você desejar manter um recurso com um editor de texto em um formulário legível, você deve mantê\-lo em um arquivo .RC separado do arquivo que o Visual C\+\+ edita.  
  
-   Se você precisar manter um recurso definido por usuário em um formato binário ou de texto que pode ser interpretado por outro editor especializado de dados, você deverá mantê\-lo em um arquivo separado de .RC para que o Visual C\+\+ não altere o formato para dados hexadecimais.  Os recursos de arquivo .WAV \(som\) na amostragem de conceitos avançados MFC [SPEAKN](../top/visual-cpp-samples.md) são um bom exemplo.  
  
 Você pode \#include um SECOND.RC nas Diretivas de Tempo de Compilação na caixa de diálogo O Conjunto Inclui:  
  
```  
#include "res\myapp.rc2"  // non-Visual C++ edited resources  
#include "second.rc"  // THE SECOND .RC FILE  
  
#include "afxres.rc"  // Standard components  
#include "afxprint.rc"  // printing/print preview resources  
```  
  
 O resultado é ilustrada no diagrama a seguir:  
  
```  
RESOURCE.H     AFXRES.H                      
       \       /                                
        \     /                                  
       MYAPP.RC  
           |                                  
           |                                
     RES\MYAPP.RC2  
     SECOND.RC    
     AFXRES.RC                     
     AFXPRINT.RC                   
```  
  
 Usando diretivas de tempo de compilação, você pode organizar seus recursos editáveis ou não do Visual C\+\+ em vários arquivos .RC, onde o "mestre" MYAPP.RC não faz nada além de \#incluir os outros arquivos .RC.  Se você estiver usando um arquivo de projeto .MAK do Visual C\+\+, você deverá incluir o arquivo .RC "mestre" no projeto para que todos os recursos incluídos por \#include sejam compilados com seu aplicativo.  
  
 **Aplicação de arquivos não editáveis do Visual C\+\+**  
  
 O arquivo RES\\MYAPP.RC2 criado com o AppWizard é um exemplo de um arquivo que contém os recursos que você *não* deseja ler acidentalmente no Visual C\+\+ e gravar novamente com perda de informações de formatação.  Para proteger contra isso, coloque as seguintes linhas no início do arquivo RES\\MYAPP.RC2:  
  
```  
#ifdef APSTUDIO_INVOKED  
    #error this file is not editable by Visual C++  
#endif //APSTUDIO_INVOKED  
```  
  
 Quando o Visual C\+\+ compila o arquivo .RC, ele define o **APSTUDIO\_INVOKED** e o **RC\_INVOKED**.  Se a estrutura de arquivo criado por AppWizard estiver corrompida e o Visual C\+\+ ler a linha de \#error anterior, ele relatará um erro fatal e anulará a leitura do arquivo .RC.  
  
 **Gerenciando os símbolos compartilhados por vários arquivos .RC do Visual C\+\+\-Edited**  
  
 Dois problemas ocorrem quando você divide seus recursos em vários arquivos de .RC que você deseja editar separadamente no Visual C\+\+:  
  
-   Convém compartilhar os mesmos símbolos entre vários arquivos .RC.  
  
-   Você precisa ajudar o Visual C\+\+ a evitar atribuir os mesmos valores numéricos de identificação para recursos distintos \(símbolos\).  
  
 O diagrama a seguir ilustra uma organização de arquivos .RC e .H que lidam com os primeiros problemas:  
  
```  
              MYAPP.RC  
             /         \  
            /           \  
MYSTRS.H   / MYSHARED.H  \  MYMENUS.H  
     \    /    /      \   \    \  
      \  /    /        \   \    \  
   MYSTRS.RC           MYMENUS.RC  
```  
  
 Nesse exemplo, os recursos de cadeia de caracteres são mantidos em um arquivo de recurso, MYSTRS.RC, e os menus são mantidos no outro, MYMENUS.RC.  Alguns símbolos, como os comandos, podem precisar ser compartilhados entre os dois arquivos.  Por exemplo, um ID\_TOOLS\_SPELL pode ser o ID de comando de menu do item Correção ortográfica em um menu de ferramentas; e também pode ser o ID da cadeia de caracteres do prompt de comando exibido pela estrutura na barra de status da janela principal do aplicativo.  
  
 O símbolo de ID\_TOOLS\_SPELL é mantido no arquivo de cabeçalho compartilhado, MYSHARED.H.  Você mantém esse arquivo de cabeçalho compartilhado manualmente com um editor de texto; o Visual C\+\+ não o edita diretamente.  Nos dois arquivos de recurso MYSTRS.RC e MYMENUS.RC, você especifica \#include MYSHARED.H nas diretivas somente leitura para MYAPP.RC, usando o comando de **Recurso Inclui**, como descrito anteriormente.  
  
 É mais conveniente antecipar um símbolo que você compartilhará antes de tentar usá\-lo para identificar algum recurso.  Adicione o símbolo ao arquivo de cabeçalho compartilhado, se você ainda não tiver incluído o arquivo de cabeçalho compartilhado usando a instrução \#include nas diretivas somente leitura do arquivo .RC, faça isso antes de usar o símbolo.  Se você não tiver antecipado o compartilhamento do símbolo dessa maneira, será necessário \(usando um editor de texto\) mover a instrução de \#define para o símbolo de MYMENUS.H para MYSHARED.H antes de usá\-lo em MYSTRS.RC.  
  
 Ao gerenciar símbolos de vários arquivos .RC, você também deve ajudar o Visual C\+\+ a evitar atribuir os mesmos valores numéricos de identificação a recursos distintos \(símbolos\).  Para qualquer arquivo .RC, o Visual C\+\+ atribui adicionalmente IDs em cada um dos quatro domínios de ID.  Entre as sessões de edição, o Visual C\+\+ mantém registro da última ID atribuída em cada um dos domínios no arquivo de cabeçalho de símbolo do arquivo .RC.  Veja o que os valores de APS\_NEXT são para um arquivo .RC vazio \(novo\):  
  
```  
#define _APS_NEXT_RESOURCE_VALUE  101  
#define _APS_NEXT_COMMAND_VALUE   40001  
#define _APS_NEXT_CONTROL_VALUE   1000  
#define _APS_NEXT_SYMED_VALUE     101  
```  
  
 **\_APS\_NEXT\_RESOURCE\_VALUE** é o próximo valor de símbolo que será usado para um recurso de caixa de diálogo, recurso de menu, e assim por diante.  O intervalo válido para valores de símbolo do recurso é 1 para 0x6FFF.  
  
 **\_APS\_NEXT\_COMMAND\_VALUE** é o próximo valor de símbolo que será usado para uma identificação de comando.  O intervalo válido para valores de símbolo de comando é 0x8000 para 0xDFFF.  
  
 **\_APS\_NEXT\_CONTROL\_VALUE** é o próximo valor de símbolo que será usado para um controle de diálogo.  O intervalo válido para valores de símbolo de comando de diálogo é 8 para 0xDFFF.  
  
 **\_APS\_NEXT\_SYMED\_VALUE** é o próximo valor de símbolo que será emitido quando você atribuir manualmente um valor de símbolo usando o comando Novo no navegador de símbolos.  
  
 O Visual C\+\+ inicia com valores ligeiramente mais altos que o menor valor válido para a criação de um novo arquivo .RC.  O AppWizard também inicializará esses valores para algo mais adequado para aplicativos MFC.  Para obter mais informações sobre intervalos de valores de ID, consulte a [Nota técnica 20](../mfc/tn020-id-naming-and-numbering-conventions.md).  
  
 Agora cada vez que você criar um novo arquivo de recurso, mesmo no mesmo projeto, o Visual C\+\+ define os mesmos valores de **\_APS\_NEXT\_**.  Isso significa que se você adicionar caixas de diálogo, por exemplo, em dois arquivos .RC diferentes, é altamente provável que o mesmo valor de \#define será atribuído caixas de diálogo diferentes.  Por exemplo, IDD\_MY\_DLG1 no primeiro arquivo .RC pode receber o mesmo número, 101, como IDD\_MY\_DLG2 em um segundo arquivo .RC.  
  
 Para evitar isso, você deve reservar um intervalo numérico separado para cada um dos quatro domínios de IDs nos respectivos arquivos .RC.  Faça isso atualizando manualmente os valores de **\_APS\_NEXT** em cada um dos arquivos .RC `before` de você começar a adicionar os recursos.  Por exemplo, se o primeiro arquivo .RC usa os valores padrão **\_APS\_NEXT**, convém atribuir os seguintes valores **\_APS\_NEXT** ao segundo arquivo .RC:  
  
```  
#define _APS_NEXT_RESOURCE_VALUE  2000  
#define _APS_NEXT_COMMAND_VALUE   42000  
#define _APS_NEXT_CONTROL_VALUE   2000  
#define _APS_NEXT_SYMED_VALUE     2000  
```  
  
 Naturalmente, ainda é possível que o Visual C\+\+ atribua tantas IDs no primeiro arquivo .RC que os valores numéricos comecem a sobrepor os valores reservados para o segundo arquivo .RC.  Você deve reservar intervalos suficientemente grandes para que isso não ocorra.  
  
 **Gerenciando dependências entre arquivos .RC, .CPP, e .H**  
  
 Quando o Visual C\+\+ salva um arquivo .RC, ele também salva as alterações de símbolo no arquivo correspondente RESOURCE.H.  Todos os seus arquivos .CPP que referenciam recursos no arquivo .RC devem incluir o arquivo RESOURCE.H, em geral do arquivo de cabeçalho mestre do seu projeto.  Isso resulta em um efeito colateral indesejado devido ao gerenciamento de projetos interno do ambiente de desenvolvimento que verifique arquivos de origem para dependências do cabeçalho.  Cada vez que você adicionar um novo símbolo no Visual C\+\+, todos os arquivos .CPP que incluem RESOURCE.H através da declaração \#include precisarão ser recompilados.  
  
 O Visual C\+\+ contorna a dependência do RESOURCE.H, incluindo o seguinte comentário como primeira linha do arquivo RESOURCE.H:  
  
```  
//{{NO_DEPENDENCIES}}  
```  
  
 O ambiente de desenvolvimento interpreta este comentário ignorando as alterações a RESOURCE.H de modo que os arquivos dependentes de .CPP não devam ser recompilados.  
  
 Visual C\+\+ sempre adiciona a linha de comentário \/\/{{NO\_DEPENDENCIES}} a um arquivo .RC quando salva o arquivo.  Em alguns casos, contornar a dependência de compilação em RESOURCE.H pode levar a erros em tempo de execução não detectados em tempo de link.  Por exemplo, se você usar o navegador do símbolo para alterar o valor numérico atribuído a um símbolo para um recurso, o recurso não será encontrado e não será carregado corretamente no tempo de execução do aplicativo se o arquivo .CPP que faz referência ao recurso não for recompilado.  Nesses casos, você deve recompilar explicitamente todos os arquivos .CPP que você souber que estão afetados pelas alterações de símbolo em RESOURCE.H ou selecionar **Recompilar Tudo**.  Se você tiver a necessidade de alterar os valores de símbolo com frequência para um determinado grupo de recursos, você provavelmente achará mais conveniente e seguro quebrar esses símbolos em um arquivo de cabeçalho somente leitura separado, conforme descrito na seção anterior [Incluindo arquivos de cabeçalho adicionais](#_mfcnotes_tn035_including).  
  
 **Como o Visual C\+\+ gerencia as informações incluídas de conjunto**  
  
 Como discutido acima, o comando Set Includes do menu Arquivo permite que você especifique três tipos de informação:  
  
-   Arquivo de Cabeçalho do Símbolo  
  
-   Diretivas do símbolo somente leitura  
  
-   Diretivas de tempo de compilação  
  
 A seguir, veja descrição de como o Visual C\+\+ mantém essas informações no arquivo .RC.  Você não precisa dessas informações para usar o Visual C\+\+, mas pode melhorar seu entendimento sobre o modo mais seguro de usar o recurso O Conjunto Inclui.  
  
 Cada um dos três tipos acima de Set Includes information é armazenado no arquivo .RC de duas formas: \(1\) como \#include ou outras diretivas que podem ser interpretadas pelo compilador de recurso, e \(2\) como recursos especiais de TEXTINCLUDE que podem ser interpretados somente pelo Visual C\+\+.  
  
 O objetivo de recurso de TEXTINCLUDE é armazenar com segurança as informações do Conjunto Include em um formulário que é prontamente apresentável na caixa de diálogo **Definir inclusões** do Visual C\+\+.  TEXTINCLUDE é um *tipo de recurso* definido pelo Visual C\+\+.  O Visual C\+\+ reconhece três recursos específicos do TEXTINCLUDE que possuem os números de identificação 1, 2 e 3:  
  
|ID do recurso TEXTINCLUDE|O tipo de conjunto inclui informações|  
|-------------------------------|-------------------------------------------|  
|1|Arquivo de Cabeçalho do Símbolo|  
|2|Diretivas do símbolo somente leitura|  
|3|Diretivas de tempo de compilação|  
  
 Cada um dos três tipos de Set Includes information é ilustrado pelos arquivos MYAPP.RC e RESOURCE.H padrão criados pelo AppWizard, conforme descrito abaixo.  Os tokens \\0 e "" entre os blocos COMEÇO e FIM são necessários pela sintaxe do RC para especificar que nenhuma cadeia de caracteres terminada e o caractere de aspas duplas, respectivamente.  
  
## Arquivo de Cabeçalho do Símbolo  
 O formulário de informações do Arquivo de cabeçalho do símbolo interpretado pelo Compilador de recursos é simplesmente uma instrução \#include:  
  
```  
#include "resource.h"  
```  
  
 O recurso correspondente TEXTINCLUDE é:  
  
```  
1 TEXTINCLUDE DISCARDABLE  
BEGIN  
   "resource.h\0"  
END  
```  
  
## Diretivas do símbolo somente leitura  
 As diretivas dos símbolos de somente leitura incluídas no início d MYAPP.RC no formulário a seguir que é interpretado pelo compilador de recursos:  
  
```  
#include "afxres.h"  
```  
  
 O recurso correspondente TEXTINCLUDE é:  
  
```  
2 TEXTINCLUDE DISCARDABLE  
BEGIN  
   "#include ""afxres.h""\r\n"  
   "\0"  
END  
```  
  
## Diretivas de tempo de compilação  
 As políticas de tempo de compilação estão incluídas no final de MYAPP.RC no formulário a seguir que é interpretado pelo compilador de recursos:  
  
```  
#ifndef APSTUDIO_INVOKED  
///////////////////////  
//  
// From TEXTINCLUDE 3  
//  
#include "res\myapp.rc2"  // non-Visual C++ edited resources  
  
#include "afxres.rc"  // Standard components  
#include "afxprint.rc"  // printing/print preview resources  
#endif  // not APSTUDIO_INVOKED  
```  
  
 A diretiva \#ifndef APSTUDIO\_INVOKED instrui o Visual C\+\+ para ignorar Políticas de Tempo de Compilação.  
  
 O recurso correspondente TEXTINCLUDE é:  
  
```  
3 TEXTINCLUDE DISCARDABLE  
BEGIN  
"#include ""res\myapp.rc2""  // non-Visual C++ edited resources\r\n"  
"\r\n"  
"#include ""afxres.rc""  // Standard components\r\n"  
"#include ""afxprint.rc""  // printing/print preview resources\r\n"  
"\0"  
END  
```  
  
## Consulte também  
 [Observações técnicas por número](../mfc/technical-notes-by-number.md)   
 [Observações técnicas por categoria](../mfc/technical-notes-by-category.md)