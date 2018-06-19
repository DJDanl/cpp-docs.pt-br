---
title: 'TN035: Usando vários arquivos de recurso e arquivos de cabeçalho com o Visual C++ | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
f1_keywords:
- vc.resources
dev_langs:
- C++
helpviewer_keywords:
- resource files, multiple
- TN035
ms.assetid: 1f08ce5e-a912-44cc-ac56-7dd93ad73fb6
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: c374e0d14375450533326be5fd406fe8147e475a
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33385372"
---
# <a name="tn035-using-multiple-resource-files-and-header-files-with-visual-c"></a>TN035: usando vários arquivos de recurso e arquivos de cabeçalho com o Visual C++
> [!NOTE]
>  A Observação técnica a seguir não foi atualizada desde que ele foi incluído primeiro na documentação online. Como resultado, alguns procedimentos e tópicos podem estar desatualizadas ou incorretas. Para obter as informações mais recentes, é recomendável que você pesquise o tópico de interesse no índice da documentação on-line.  
  
 Esta anotação descreve como o editor de recursos do Visual C++ oferece suporte a vários arquivos de recurso e arquivos de cabeçalho compartilhados em um único projeto ou compartilhados em vários projetos e como você pode aproveitar esse suporte. Esta anotação responde a essas perguntas:  
  
-   Quando você quiser dividir um projeto em vários arquivos de recurso e/ou arquivos de cabeçalho, e como fazê-lo  
  
-   Como compartilhar um cabeçalho comuns. Arquivo H entre os dois. Arquivos RC  
  
-   Como você dividir os recursos de projeto em várias. Arquivos RC  
  
-   Como você (e as ferramentas) gerencio dependências de compilação entre. RC. CPP, e. Arquivos H  
  
 Você deve estar ciente de que, se você adicionar um arquivo de recursos adicionais ao seu projeto, ClassWizard não reconhecerá os recursos no arquivo de inclusão.  
  
 Essa observação é estruturada para responder às perguntas acima da seguinte maneira:  
  
- **Visão geral de como Visual C++ gerencia arquivos de recurso e arquivos de cabeçalho** fornece uma visão geral de como o comando inclui o recurso definido no Visual C++ permite que você use vários arquivos de recurso e arquivos de cabeçalho no mesmo projeto.  
  
- **Análise de AppWizard criados. RC e. Arquivos H** examina os vários arquivos de cabeçalho e recursos são usados por um aplicativo criado AppWizard. Esses arquivos servem como um bom modelo para arquivos de recursos adicionais e arquivos de cabeçalho, que talvez você queira adicionar ao seu projeto.  
  
- **Incluindo arquivos de cabeçalho adicionais** descreve onde você pode querer incluir vários arquivos de cabeçalho e fornece detalhes como fazer isso.  
  
- **Compartilhar um arquivo de cabeçalho entre os dois. Arquivos RC** mostra como você pode compartilhar um arquivo de cabeçalho entre vários. Arquivos RC em diferentes projetos, ou talvez no mesmo projeto.  
  
- **Usando vários arquivos de recurso no mesmo projeto** descreve onde deseja dividir seu projeto em várias. RC arquivos e fornece detalhes de como fazer isso.  
  
- **Imposição de não editável arquivos do Visual C++** descreve como você pode verificar se o Visual C++ não edite e reformatar acidentalmente um recurso personalizado.  
  
- **Gerenciando símbolos compartilhados por vários Visual C++ editados. Arquivos RC** descreve como compartilhar os mesmo símbolos em vários. Arquivos RC e como evitar a atribuição de valores numéricos de ID duplicados.  
  
- **As dependências entre o gerenciamento. RC. CPP, e. Arquivos H** descreve como Visual C++ evita a recompilação desnecessários. Arquivos CPP que dependem de arquivos de símbolos de recurso.  
  
- **Como o Visual C++ gerencia conjunto inclui informações** fornece detalhes técnicos sobre como o Visual C++ mantém o controle de vários (aninhado). Arquivos RC e vários arquivos de cabeçalho são #include'd por um. Arquivo RC.  
  
 **Visão geral de como o Visual C++ gerencia arquivos de recurso e arquivos de cabeçalho**  
  
 Visual C++ gerencia um único. Arquivo de recurso RC e correspondente. Arquivo de cabeçalho H como um par firmemente acoplado de arquivos. Quando você editar e salvar os recursos em um. Arquivo RC, você indiretamente editar e salvar símbolos no correspondente. Arquivo de H. Embora você possa abrir e editar vários. Arquivos RC no momento (usando a interface do usuário do Visual C++ MDI) para qualquer dado. Arquivo RC indiretamente editar exatamente um arquivo de cabeçalho correspondente.  
  
 **Arquivo de cabeçalho de símbolo**  
  
 Por padrão, Visual C++ sempre nomeia o arquivo de cabeçalho recurso correspondente. H, independentemente do nome do arquivo de recurso (por exemplo, MYAPP. RC). Usando o **inclui recursos** comando o **exibição** menu do Visual C++, você pode alterar o nome deste arquivo de cabeçalho, atualizando o arquivo do arquivo de cabeçalho de símbolo no **definir inclui**caixa de diálogo.  
  
 **Diretivas de símbolo somente leitura**  
  
 Embora o Visual C++ somente edita um arquivo de cabeçalho para qualquer dado. Arquivo RC, Visual C++ dá suporte a referências para símbolos definido nos arquivos de cabeçalho adicionais de somente leitura. Usando o **inclui recursos** comando o **exibição** menu no Visual C++, você pode especificar qualquer número de arquivos de cabeçalho adicionais de somente leitura como diretivas de símbolo somente leitura. A restrição "somente leitura" significa que, quando você adicionar um novo recurso na. Arquivo RC, você pode usar um símbolo definido no arquivo de cabeçalho de somente leitura; mas, se você excluir o recurso, o símbolo ainda permanece definido no arquivo de cabeçalho de somente leitura. Você não pode alterar o valor numérico atribuído a um símbolo de somente leitura.  
  
 **Diretivas de tempo de compilação**  
  
 Visual C++ também dá suporte a aninhamento de arquivos de recursos, onde um. Arquivo RC é #include'd dentro de outra. Quando você edita um determinado. Arquivo RC usando o Visual C++, todos os recursos na #include'd arquivos não são visíveis. Mas quando você compila o. Arquivo RC, o #include'd arquivos também são compilados. Usando o **inclui recursos** comando o **exibição** menu do Visual C++, você pode especificar qualquer número de #include'd. Arquivos RC como diretivas de tempo de compilação.  
  
 Observe o que acontece se você ler no Visual C++ um. RC arquivo #include do outro. Arquivo RC *não* especificado como uma diretiva de tempo de compilação. Essa situação pode surgir quando você colocar no Visual C++ um. Arquivo RC que você tinha sido anteriormente mantendo manualmente com um editor de texto. Quando o Visual C++ lê a #include'd. Arquivo RC, ele mescla o #include'd recursos no pai. Arquivo RC. Quando você salva o pai. Arquivo RC, o #include instrução, de fato, será substituído pelo #include'd recursos. Se você não quiser que essa mesclagem ocorra, você deve remover o #include instrução do pai. Arquivo RC *anterior* para lê-los no Visual C++; usando o Visual C++, em seguida, adicione novamente o mesmo #include instrução como uma diretiva de tempo de compilação.  
  
 Visual C++ salva em um. Os três tipos de acima de arquivo RC definir inclui informações (arquivo de cabeçalho de símbolo, diretivas de símbolo somente leitura e diretivas de tempo de compilação) #include diretivas *e* em recursos TEXTINCLUDE. Os recursos TEXTINCLUDE, um detalhe de implementação que você normalmente não precisa lidar com, são explicados em [como Visual C++ gerencia inclui informações sobre o conjunto](#_mfcnotes_tn035_set_includes).  
  
 **Análise de AppWizard criados. RC e. Arquivos H**  
  
 Examinar o código de aplicativo produzido pelo AppWizard fornece informações sobre como o Visual C++ gerencia vários arquivos de recurso e arquivos de cabeçalho. Os trechos de código examinados abaixo são de um aplicativo de MYAPP produzido pelo AppWizard usando as opções padrão.  
  
 Um aplicativo criado AppWizard usa vários arquivos de recurso e vários arquivos de cabeçalho, como resumido no diagrama a seguir:  
  
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
  
 Você pode exibir essas várias relações de arquivo usando o comando inclui o arquivo do Visual C++/Set.  
  
 MYAPP.RC  
 O arquivo de recurso do aplicativo que você editar usando o Visual C++.  
  
 RECURSO. H é o arquivo de cabeçalho específico do aplicativo. Ele é sempre chamado recurso. H por AppWizard, consistente com o padrão do Visual C++ de nomenclatura de arquivo de cabeçalho. O #include para esse arquivo de cabeçalho é a primeira instrução no arquivo de recurso (MYAPP. RC):  
  
```  
//Microsoft Visual C++ generated resource script  
//  
#include "resource.h"  
```  
  
 RES\MYAPP.RC2  
 Contém recursos que não serão editados pelo Visual C++, mas serão incluídos no final compilado. Arquivo EXE. AppWizard não cria nenhum tais recursos por padrão, como Visual C++ pode editar todos os recursos padrão, incluindo o recurso de versão (um novo recurso nesta versão). Um arquivo vazio é gerado pelo AppWizard caso você deseja adicionar seus próprios recursos de formatação personalizados para este arquivo.  
  
 Se você usar recursos formatados personalizados, você pode adicioná-los para RES\MYAPP. RC2 e editá-los usando o editor de texto do Visual C++.  
  
 AFXRES. RC e AFXPRINT. RC contêm recursos padrão necessários para determinados recursos do framework. Como RES\MYAPP. RC2, esses dois arquivos de recursos fornecidos pelo framework são #include'd no final do MYAPP. RC e elas são especificadas nas diretivas de tempo de compilação da caixa de diálogo Definir inclui. Portanto, você não diretamente exibir ou editar esses recursos de estrutura enquanto você editar MYAPP. RC no Visual C++, mas eles são compilados no binário do aplicativo. Arquivo RES e final. Arquivo EXE. Para obter mais informações sobre os recursos de estrutura padrão, incluindo procedimentos para modificá-los, consulte [23 de observação técnica](../mfc/tn023-standard-mfc-resources.md).  
  
 AFXRES. H define símbolos padrão, como `ID_FILE_NEW`, usada pelo framework e usado especificamente em AFXRES. RC. AFXRES. H também # do include WINRES. H, que contém um subconjunto do WINDOWS. H que são necessárias para gerado pelo Visual C++. Arquivos RC, bem como AFXRES. RC. Os símbolos definidos no AFXRES. H estão disponíveis como editar o arquivo de recurso do aplicativo (MYAPP. RC). Por exemplo, `ID_FILE_NEW` é usado para o arquivo novo item de menu no MYAPP. Recurso de menu do RC. Você não pode alterar ou excluir esses símbolos definidos pelo framework.  
  
## <a name="_mfcnotes_tn035_including"></a> Incluindo arquivos de cabeçalho adicionais  
  
 O aplicativo criado AppWizard inclui apenas dois arquivos de cabeçalho: recurso. H e AFXRES. H. Somente os recursos. H é específica do aplicativo. Talvez seja necessário incluir arquivos de cabeçalho adicionais de somente leitura nos seguintes casos:  
  
 O arquivo de cabeçalho é fornecido por uma fonte externa, ou você deseja compartilhar o arquivo de cabeçalho entre vários projetos ou em várias partes do mesmo projeto.  
  
 O arquivo de cabeçalho tem formatação e os comentários que você não deseja que o Visual C++ para alterar ou filtrar quando ele salva o arquivo. Por exemplo, talvez você queira preservar # do define que usar aritmética simbólica, como:  
  
```  
#define RED 0  
#define BLUE 1  
#define GREEN 2  
#define ID_COLOR_BUTTON 1001  
#define ID_RED_BUTTON (ID_COLOR_BUTTON + RED)  
#define ID_BLUE_BUTTON (ID_COLOR_BUTTON + BLUE)  
#define ID_GREEN_BUTTON (ID_COLOR_BUTTON + GREEN)  
```  
  
 Você pode incluir arquivos de cabeçalho adicionais de somente leitura usando o **inclui recursos** comando para especificar o #include instrução como uma segunda diretiva de símbolo de somente leitura, como em:  
  
```  
#include "afxres.h"  
#include "second.h"  
```  
  
 O novo diagrama de relação de arquivo agora é semelhante a:  
  
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
  
 **Compartilhar um arquivo de cabeçalho entre os dois. Arquivos RC**  
  
 Você talvez queira compartilhar um arquivo de cabeçalho entre os dois. Arquivos RC que estão em diferentes projetos ou possivelmente o mesmo projeto. Para fazer isso, basta aplica a técnica de diretivas de somente leitura descrita acima para ambos. Arquivos RC. No caso em que os dois. Arquivos RC são para aplicativos diferentes (projetos diferentes), o resultado é ilustrado no diagrama a seguir:  
  
```  
    RESOURCE.H AFXRES.H   RESOURCE.H    
 (for MYAPP1) SECOND.H   (for MYAPP2)               
 \       /     \       /             
 \     /       \     /               
    MYAPP1.RC MYAPP2.RC */    \        /     \ */      \      /       \              
RES\MYAPP1.RC2  AFXRES.RC     RES\MYAPP2.RC2                
    AFXPRINT.RC 
```  
  
 O caso em que o segundo arquivo de cabeçalho é compartilhado por dois. Arquivos RC no mesmo aplicativo (projeto) é discutido abaixo.  
  
 **Usando vários arquivos de recurso no mesmo projeto**  
  
 Suportam a várias Visual C++ e o compilador de recurso. Arquivos RC no mesmo projeto através de # do include de um. Arquivo RC dentro de outra. Vários aninhamento é permitido. Há vários motivos para dividir os recursos do projeto em várias. Arquivos RC:  
  
-   É mais fácil de gerenciar um grande número de recursos entre vários membros da equipe de projeto se você dividir os recursos em vários. Arquivos RC. Se você usar um pacote de gerenciamento de controle de origem para fazer check-out de arquivos e check-in de alterações, dividir os recursos em vários. Arquivos RC oferecem um controle mais preciso sobre o gerenciamento de alterações em recursos.  
  
-   Se você quiser usar diretivas de pré-processador, como #ifdef, #endif, e #define, para partes de seus recursos, você deve isolá-los em recursos somente leitura que serão compilados pelo compilador de recurso.  
  
-   Componente. Arquivos RC irá carregar e salvar mais rápido em Visual C++ que uma composição. Arquivo RC.  
  
-   Se você deseja manter um recurso com um editor de texto em um formato legível, mantê-lo em um. Edição de arquivos RC separado de um Visual C++.  
  
-   Se você precisar manter um recurso definido pelo usuário em um formulário de texto ou binário que pode ser interpretado por outro editor de dados especializado, você deverá mantê-lo em um separado. Arquivo RC para que Visual C++ não altera o formato de dados hexadecimal. A. Recursos de arquivos WAV (som) no exemplo de conceitos avançados do MFC [SPEAKN](../visual-cpp-samples.md) são um bom exemplo.  
  
 Você pode #include um segundo. RC nas diretivas de tempo de compilação na caixa de diálogo Definir inclui:  
  
```  
#include "res\myapp.rc2"  // non-Visual C++ edited resources  
#include "second.rc"  // THE SECOND .RC FILE  
  
#include "afxres.rc"  // Standard components  
#include "afxprint.rc"  // printing/print preview resources  
```  
  
 O resultado é ilustrado no diagrama a seguir:  
  
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
  
 Usando diretivas de tempo de compilação, você pode organizar seus recursos Visual C++ editável e não editável em vários. Arquivos RC, onde o "mestre" MYAPP. RC não faz nada, mas #include a outra. Arquivos RC. Se você estiver usando um projeto do Visual C++. Arquivo MAK, em seguida, você deve incluir o "mestre". RC do arquivo no projeto assim que todos os a #include'd os recursos são compilados com o seu aplicativo.  
  
 **Imposição de arquivos não editável Visual C++**  
  
 RES\MYAPP AppWizard criados. Arquivo RC2 é um exemplo de um arquivo que contém os recursos que você *não* ler acidentalmente em Visual C++ e depois gravá-lo de volta com a perda de informações de formatação. Para proteger contra isso, coloque as seguintes linhas no início do RES\MYAPP. Arquivo RC2:  
  
```  
#ifdef APSTUDIO_INVOKED  
 #error this file is not editable by Visual C++  
#endif //APSTUDIO_INVOKED  
```  
  
 Quando o Visual C++ compila o. Arquivo RC, ela define **APSTUDIO_INVOKED** , bem como **RC_INVOKED**. Se a estrutura de arquivos criado AppWizard está corrompida e Visual C++ lê a linha #error acima, ele relata um erro fatal e anular a leitura da. Arquivo RC.  
  
 **Gerenciando símbolos compartilhados por vários Visual C++ editados. Arquivos RC**  
  
 Dois problemas podem surgir quando você divide os seus recursos em vários. Arquivos RC que você deseja editar separadamente no Visual C++:  
  
-   Deseja compartilhar os mesmo símbolos em vários. Arquivos RC.  
  
-   Você precisa evitar Visual C++ atribuir os mesmos valores numéricos de ID para recursos diferentes (símbolos).  
  
 O diagrama a seguir ilustra uma organização. RC e. Arquivos H que lida com o primeiro problema:  
  
```  
    MYAPP.RC */         \ */           \  
MYSTRS.H   / MYSHARED.H  \  MYMENUS.H  
 \    /    /      \   \    \  
 \  /    /        \   \    \  
    MYSTRS.RC MYMENUS.RC  
```  
  
 Neste exemplo, os recursos de cadeia de caracteres são mantidos em um arquivo de recurso, MYSTRS. Menus e RC são mantidas em outro, MYMENUS. RC. Alguns símbolos, como comandos, talvez precise ser compartilhado entre os dois arquivos. Por exemplo, um ID_TOOLS_SPELL pode ser a ID de comando de menu para o item de ortografia em um menu de ferramentas. e também pode ser a ID de cadeia de caracteres do prompt de comando exibido pelo framework na barra de status de janela principal do aplicativo.  
  
 O símbolo ID_TOOLS_SPELL é mantido no arquivo de cabeçalho compartilhado, MYSHARED. H. Manter esse arquivo de cabeçalho compartilhado manualmente com um editor de texto. Visual C++ diretamente não editá-lo. No recurso de dois arquivos MYSTRS. RC e MYMENUS. RC, especifique #include MYSHARED. H nas diretivas de somente leitura para MYAPP. RC, usando o **inclui recursos** de comando, conforme descrito anteriormente.  
  
 É mais conveniente prever um símbolo compartilharão antes de tentar usar para identificar qualquer recurso. Adicionar o símbolo para o arquivo de cabeçalho compartilhado e, se você ainda não tiver #include'd o arquivo de cabeçalho compartilhado nas diretivas de somente leitura para o. RC do arquivo, antes de usar o símbolo. Se não previu compartilhando o símbolo dessa forma, você terá que manualmente (usando um editor de texto) mover o #define a instrução para o símbolo de, digamos, MYMENUS. H para MYSHARED. H antes de usá-lo em MYSTRS. RC.  
  
 Quando você gerencia os símbolos em vários. Arquivos RC, você também deve evitar Visual C++ atribuir os mesmos valores numéricos de ID para recursos diferentes (símbolos). Para qualquer dado. Arquivo RC, Visual C++ incrementalmente atribui IDs em cada um dos quatro domínios a ID. Entre as sessões de edição Visual C++ mantém controle sobre a última ID ele atribuído em cada um dos domínios no arquivo de cabeçalho de símbolo para o. Arquivo RC. Os valores APS_NEXT são para vazio (novo). Arquivo RC:  
  
```  
#define _APS_NEXT_RESOURCE_VALUE  101  
#define _APS_NEXT_COMMAND_VALUE   40001  
#define _APS_NEXT_CONTROL_VALUE   1000  
#define _APS_NEXT_SYMED_VALUE     101  
```  
  
 **_APS_NEXT_RESOURCE_VALUE** é o próximo valor de símbolo que será usado para um recurso de caixa de diálogo, recurso de menu e assim por diante. O intervalo válido para valores de símbolo de recurso é 1 para 0x6FFF.  
  
 **_APS_NEXT_COMMAND_VALUE** é o próximo valor de símbolo que será usado para uma identificação de comando. O intervalo válido para valores de símbolo de comando é 0x8000 a 0xDFFF.  
  
 **_APS_NEXT_CONTROL_VALUE** é o próximo valor de símbolo que será usado para um controle de caixa de diálogo. O intervalo válido para valores de símbolo de controle de caixa de diálogo é 8 a 0xDFFF.  
  
 **_APS_NEXT_SYMED_VALUE** é o próximo valor de símbolo que será emitido quando você atribuir manualmente um valor de símbolo usando o comando de novo no navegador do símbolo.  
  
 Visual C++ será iniciada com valores ligeiramente maiores que jurídico menor valor quando criar um novo. Arquivo RC. AppWizard também inicializar esses valores para algo mais apropriado para aplicativos MFC. Para obter mais informações sobre intervalos de valores de ID, consulte [20 de observação técnica](../mfc/tn020-id-naming-and-numbering-conventions.md).  
  
 Agora, sempre que você criar um novo arquivo de recursos, até mesmo no mesmo projeto, o Visual C++ define a mesma **_APS_NEXT\_**  valores. Isso significa que se você adicionar, digamos, várias caixas de diálogo em duas diferentes. Arquivos RC, é muito provável que o mesmo #define valor será atribuído a diferentes caixas de diálogo. Por exemplo, IDD_MY_DLG1 no primeiro. Arquivo RC pode ter o mesmo número, 101, como IDD_MY_DLG2 em um segundo. Arquivo RC.  
  
 Para evitar isso, você deve reservar um intervalo numérico separado para cada um dos quatro domínios de IDs do respectivo. Arquivos RC. Para fazer isso, atualizar manualmente o **_APS_NEXT** valores em cada o. Arquivos RC `before` iniciar a adição de recursos. Por exemplo, se o primeiro. Arquivo RC usa o padrão **_APS_NEXT** valores, em seguida, talvez você queira atribuir a seguinte **_APS_NEXT** valores para o segundo. Arquivo RC:  
  
```  
#define _APS_NEXT_RESOURCE_VALUE  2000  
#define _APS_NEXT_COMMAND_VALUE   42000  
#define _APS_NEXT_CONTROL_VALUE   2000  
#define _APS_NEXT_SYMED_VALUE     2000  
```  
  
 Obviamente, ainda é possível que o Visual C++ atribuirá muitas IDs no primeiro. Arquivo RC que os valores numéricos iniciarem sobrepor os reservado para o segundo. Arquivo RC. Você deve reservar intervalos grandes o suficiente para que isso não acontece.  
  
 **As dependências entre o gerenciamento. RC. CPP, e. Arquivos H**  
  
 Quando o Visual C++ salva um. Arquivo RC, ele também salva as alterações de símbolo para o recurso correspondente. Arquivo de H. Qualquer uma das suas. Arquivos CPP que fazem referência a recursos em de. Arquivo RC deve #include do recurso. Arquivo H, geralmente no arquivo de cabeçalho principal do seu projeto. Isso leva a um efeito colateral indesejável devido ao gerenciamento de projeto interno do ambiente de desenvolvimento que examina os arquivos de origem para as dependências de cabeçalho. Sempre que você adicionar um novo símbolo no Visual C++, todos os. Arquivo CPP #include recursos. H precisa ser recompilado.  
  
 Visual C++, contorna a dependência do recurso. H, incluindo o comentário a seguir como a primeira linha do recurso. Arquivo H:  
  
```  
//{{NO_DEPENDENCIES}}  
```  
  
 O ambiente de desenvolvimento interpreta este comentário ao ignorar as alterações ao recurso. Assim que é dependente de H. Arquivos CPP não precisa ser recompilado.  
  
 Visual C++ sempre adiciona o //{{NO_DEPENDENCIES}} comentário de linha para um. Arquivo RC quando ele salva o arquivo. Em alguns casos, desvio de dependência de compilação no recurso. H pode resultar em erros de tempo de execução sem serem detectados em tempo de link. Por exemplo, se você usar o navegador de símbolo para alterar o valor numérico atribuído a um símbolo de um recurso, o recurso de não ser corretamente localizado e carregado no caso de tempo de execução do aplicativo do. Arquivo CPP referindo-se ao recurso não é recompilado. Nesses casos, você deve recompilar qualquer explicitamente. Arquivos CPP que você sabe que são afetados pelas alterações de símbolo no recurso. H ou selecione **recriar todos os**. Se você tiver a necessidade de alterações frequentes valores de símbolo para um determinado grupo de recursos, você provavelmente achará mais conveniente e segura quebrar esses símbolos em um arquivo de cabeçalho separado de somente leitura, conforme descrito na seção acima [incluindo Arquivos de cabeçalho adicionais](#_mfcnotes_tn035_including).  
  
## <a name="_mfcnotes_tn035_set_includes"></a> Como o Visual C++ gerencia conjunto inclui informações**  
  
 Como discutido acima, no menu Arquivo inclui definir comando lhe permite especificar três tipos de informações:  
  
-   Arquivo de cabeçalho de símbolo  
  
-   Diretivas de símbolo somente leitura  
  
-   Diretivas de tempo de compilação  
  
 A seguir descreve como o Visual C++ mantém essas informações em um. Arquivo RC. Essas informações para usar o Visual C++ não é necessário, mas ele pode aprimorar seu entendimento para que a maneira mais confiável, você pode usar o recurso Definir inclui.  
  
 Cada um dos três tipos de conjunto inclui informações anteriores é armazenada em de. Arquivo RC em duas formas: (1) como #include ou outras diretivas pode ser interpretadas pelo compilador de recurso e (2) como recursos TEXTINCLUDE especiais pode ser interpretados somente pelo Visual C++.  
  
 A finalidade do recurso TEXTINCLUDE é armazenar com segurança definida incluem informações em um formulário que é prontamente apresentável no Visual C++ **definir inclui** caixa de diálogo. TEXTINCLUDE é um *tipo de recurso* definido pelo Visual C++. Visual C++ reconhece três recursos específicos de TEXTINCLUDE que têm o recurso de números de identificação de 1, 2 e 3:  
  
|ID do recurso TEXTINCLUDE|Tipo de conjunto inclui informações|  
|-----------------------------|--------------------------------------|  
|1|Arquivo de cabeçalho de símbolo|  
|2|Diretivas de símbolo somente leitura|  
|3|Diretivas de tempo de compilação|  
  
 Cada um dos três tipos de informações de conjunto inclui é ilustrada MYAPP padrão. RC e do recurso. Arquivos de H criados pelo AppWizard, conforme descrito abaixo. O \0 extra e "" tokens entre blocos BEGIN e END são necessárias para a sintaxe RC especificar zero cadeias de caracteres terminadas e o caractere de aspas duplas, respectivamente.  
  
## <a name="symbol-header-file"></a>Arquivo de cabeçalho de símbolo  
 O formato das informações do arquivo de cabeçalho de símbolo interpretados pelo compilador de recurso é simplesmente um #include instrução:  
  
```  
#include "resource.h"  
```  
  
 O recurso TEXTINCLUDE correspondente é:  
  
```  
1 TEXTINCLUDE DISCARDABLE  
BEGIN  
 "resource.h\0"  
END  
```  
  
## <a name="read-only-symbol-directives"></a>Diretivas de símbolo somente leitura  
 Diretivas de símbolo somente leitura são incluídas na parte superior da MYAPP. RC no seguinte formato pode ser interpretado pelo compilador de recurso:  
  
```  
#include "afxres.h"  
```  
  
 O recurso TEXTINCLUDE correspondente é:  
  
```  
2 TEXTINCLUDE DISCARDABLE  
BEGIN  
   "#include ""afxres.h""\r\n"  
   "\0"  
END  
```  
  
## <a name="compile-time-directives"></a>Diretivas de tempo de compilação  
 Diretivas de tempo de compilação são incluídas no final do MYAPP. RC no seguinte formato pode ser interpretado pelo compilador de recurso:  
  
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
  
 A diretiva APSTUDIO_INVOKED #ifndef instrui o Visual C++ para ignorar as diretivas de tempo de compilação.  
  
 O recurso TEXTINCLUDE correspondente é:  
  
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
  
## <a name="see-also"></a>Consulte também  
 [Observações técnicas por número](../mfc/technical-notes-by-number.md)   
 [Observações técnicas por categoria](../mfc/technical-notes-by-category.md)

