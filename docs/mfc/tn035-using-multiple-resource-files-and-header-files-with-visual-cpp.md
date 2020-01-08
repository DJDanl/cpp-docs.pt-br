---
title: 'TN035: usando vários arquivos de recurso e arquivos de cabeçalho com o Visual C++'
ms.date: 11/04/2016
f1_keywords:
- vc.resources
helpviewer_keywords:
- resource files, multiple
- TN035
ms.assetid: 1f08ce5e-a912-44cc-ac56-7dd93ad73fb6
ms.openlocfilehash: 23d4fdeb82ed7eea97a104e111cd022a87626df4
ms.sourcegitcommit: a5fa9c6f4f0c239ac23be7de116066a978511de7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/20/2019
ms.locfileid: "75302166"
---
# <a name="tn035-using-multiple-resource-files-and-header-files-with-visual-c"></a>TN035: usando vários arquivos de recurso e arquivos de cabeçalho com o Visual C++

> [!NOTE]
> A observação técnica a seguir não foi atualizada desde que foi incluída pela primeira vez na documentação online. Como resultado, alguns procedimentos e tópicos podem estar desatualizados ou incorretos. Para obter as informações mais recentes, é recomendável que você pesquise o tópico de interesse no índice de documentação online.

Esta observação descreve como o editor C++ de recursos visuais dá suporte a vários arquivos de recursos e arquivos de cabeçalho compartilhados em um único projeto ou compartilhados entre vários projetos e como você pode aproveitar esse suporte. Esta observação responde a estas perguntas:

- Quando você pode desejar dividir um projeto em vários arquivos de recursos e/ou arquivos de cabeçalho e como fazer isso

- Como você compartilha um cabeçalho comum. Arquivo H entre dois. Arquivos RC

- Como dividir os recursos do projeto em vários. Arquivos RC

- Como você (e as ferramentas) gerencia as dependências de compilação entre o. RC,. CPP e. Arquivos H

Você deve estar ciente de que, se você adicionar um arquivo de recurso adicional ao seu projeto, o ClassWizard não reconhecerá os recursos no arquivo adicionado.

Esta observação é estruturada para responder às perguntas acima da seguinte maneira:

- **Visão geral de como C++ o Visual gerencia arquivos de recursos e arquivos de cabeçalho** fornece uma visão geral de como o conjunto C++ de recursos inclui o comando no Visual permite que você use vários arquivos de recursos e arquivos de cabeçalho no mesmo projeto.

- **Análise de AppWizard. RC e. Os arquivos H** examinam os vários arquivos de cabeçalho e recurso que são usados por um aplicativo AppWizard. Esses arquivos servem como um bom modelo para arquivos de recursos adicionais e arquivos de cabeçalho que talvez você queira adicionar ao seu projeto.

- **Incluir arquivos de cabeçalho adicionais** descreve onde você pode desejar incluir vários arquivos de cabeçalho e fornece detalhes sobre como fazer isso.

- **Compartilhando um arquivo de cabeçalho entre dois. Os arquivos RC** mostram como você pode compartilhar um arquivo de cabeçalho entre vários. Arquivos RC em projetos diferentes, ou talvez no mesmo projeto.

- **O uso de vários arquivos de recursos no mesmo projeto** descreve onde você pode querer dividir o projeto em vários. Arquivos RC e fornece detalhes sobre como fazer isso.

- **A imposição de arquivos visuais C++ não editáveis** descreve como você pode garantir C++ que o Visual não edite e reformate involuntariamente um recurso personalizado.

- **Gerenciando símbolos compartilhados por vários C++elementos visuais-editados. Os arquivos RC** descrevem como compartilhar os mesmos símbolos em vários. Arquivos RC e como evitar atribuir valores numéricos de ID duplicados.

- **Gerenciando dependências entre. RC,. CPP e. Os arquivos H** descrevem como C++ o Visual evita a recompilação desnecessária. Arquivos CPP que dependem de arquivos de símbolo de recurso.

- **Como o C++ Visual Administrations Set inclui informações** fornece detalhes técnicos sobre C++ como o Visual mantém o controle de vários (aninhados). Arquivos RC e vários arquivos de cabeçalho #includedos por um. Arquivo RC.

## <a name="overview-of-how-visual-c-manages-resource-files-and-header-files"></a>Visão geral de como C++ o Visual gerencia arquivos de recursos e arquivos de cabeçalho

O C++ Visual gerencia um único. Arquivo de recursos RC e um correspondente. O arquivo de cabeçalho H como um par de arquivos rigidamente acoplado. Quando você edita e salva recursos em um. Arquivo RC, você edita e salva indiretamente os símbolos no correspondente. Arquivo H. Embora você possa abrir e editar vários. Arquivos RC por vez (usando a interface C++de usuário do MDI do Visual) para qualquer um. Arquivo RC você edita indiretamente exatamente um arquivo de cabeçalho correspondente.

### <a name="symbol-header-file"></a>Arquivo de cabeçalho de símbolo

Por padrão, Visual C++ sempre nomeia o recurso de arquivo de cabeçalho correspondente. H, independentemente do nome do arquivo de recurso (por exemplo, MYAPP. RC). O uso do **recurso inclui** o comando do menu **Exibir** no C++Visual, você pode alterar o nome desse arquivo de cabeçalho atualizando o arquivo de cabeçalho de símbolo na caixa de diálogo **definir inclusões** .

### <a name="read-only-symbol-directives"></a>Diretivas de símbolo somente leitura

Embora o C++ Visual edite apenas um arquivo de cabeçalho para qualquer dado. Arquivo RC, Visual C++ dá suporte a referências a símbolos definidos em arquivos de cabeçalho somente leitura adicionais. O uso do **recurso inclui** o comando do menu **Exibir** no C++Visual, você pode especificar qualquer número de arquivos de cabeçalho somente leitura adicionais como diretivas de símbolo somente leitura. A restrição "somente leitura" significa que, quando você adiciona um novo recurso no. Arquivo RC, você pode usar um símbolo definido no arquivo de cabeçalho somente leitura; Mas se você excluir o recurso, o símbolo ainda permanecerá definido no arquivo de cabeçalho somente leitura. Você não pode alterar o valor numérico atribuído a um símbolo somente leitura.

### <a name="compile-time-directives"></a>Diretivas de tempo de compilação

O C++ Visual também dá suporte ao aninhamento de arquivos de recursos, em que um. O arquivo RC é #includedo dentro de outro. Quando você edita um determinado. Arquivo RC usando Visual C++, todos os recursos nos arquivos #include não são visíveis. Mas, quando você compila o. Arquivo RC, os arquivos #include também são compilados. O uso do **recurso inclui** o comando do menu **Exibir** no C++Visual, você pode especificar qualquer número de #include. Arquivos RC como diretivas de tempo de compilação.

Observe o que acontece se você ler no C++ Visual um. Arquivo RC que #include o outro. Arquivo RC que *não* é especificado como uma diretiva de tempo de compilação. Essa situação pode surgir quando você traz para o C++ Visual um. O arquivo RC que você já estava mantendo manualmente com um editor de texto. Quando o C++ Visual lê o #include. O arquivo RC mescla os recursos #includes no pai. Arquivo RC. Quando você salva o pai. O arquivo RC, a instrução #include, em vigor, será substituído pelos recursos #include. Se você não quiser que essa mesclagem aconteça, remova a instrução #include do pai. Arquivo RC *antes* de lê-lo no C++Visual; em seguida, C++usando o Visual, adicione novamente a mesma instrução #include como uma diretiva de tempo de compilação.

O C++ Visual salva em um. Arquivo RC os três tipos de conjunto acima incluem informações (arquivo de cabeçalho de símbolo, diretivas de símbolo somente leitura e diretivas de tempo de compilação) em #include diretivas *e* em recursos de TEXTINCLUDE. Os recursos do TEXTINCLUDE, um detalhe de implementação que você normalmente não precisa lidar, são explicados em [como os C++ conjuntos de gerenciamento Visual incluem informações](#_mfcnotes_tn035_set_includes).

## <a name="analysis-of-appwizard-created-rc-and-h-files"></a>Análise de AppWizard. RC e. Arquivos H

Examinar o código do aplicativo produzido por AppWizard fornece informações sobre como C++ o Visual gerencia vários arquivos de recursos e arquivos de cabeçalho. Os trechos de código examinados abaixo são de um aplicativo MYAPP produzido por AppWizard usando as opções padrão.

Um aplicativo AppWizard usa vários arquivos de recursos e vários arquivos de cabeçalho, conforme resumido no diagrama abaixo:

```Diagram
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

Você pode exibir essas várias relações de arquivo usando o C++ comando Visual file/Set inclui.

MyApp. RC
O arquivo de recurso de aplicativo que você edita C++usando Visual.

Kit. H é o arquivo de cabeçalho específico do aplicativo. Ele sempre é chamado de recurso. H por AppWizard, consistente com a C++nomeação padrão do arquivo de cabeçalho do Visual. O #include para esse arquivo de cabeçalho é a primeira instrução no arquivo de recurso (MYAPP. RC):

```rc
//Microsoft Visual C++ generated resource script
//
#include "resource.h"
```

RES\MYAPP. RC2
Contém recursos que não serão editados pelo Visual C++ , mas serão incluídos no final compilado. Arquivo EXE. O AppWizard não cria tais recursos por padrão, já C++ que o Visual pode editar todos os recursos padrão, incluindo o recurso de versão (um novo recurso nesta versão). Um arquivo vazio é gerado pelo AppWizard caso você queira adicionar seus próprios recursos formatados personalizados a esse arquivo.

Se você usar recursos formatados personalizados, poderá adicioná-los ao RES\MYAPP. RC2 e editá-los usando C++ o editor de texto visual.

AFXRES. RC e AFXPRINT. RC contêm recursos padrão exigidos por determinados recursos da estrutura. Como RES\MYAPP. RC2, esses dois arquivos de recursos fornecidos pela estrutura são #include no final do MYAPP. RC, e eles são especificados nas diretivas de tempo de compilação da caixa de diálogo Set includes. Portanto, você não exibe ou edita diretamente esses recursos de estrutura enquanto edita MYAPP. RC no Visual C++, mas eles são compilados no binário do aplicativo. Arquivo RES e final. Arquivo EXE. Para obter mais informações sobre os recursos de estrutura padrão, incluindo procedimentos para modificá-los, consulte a [Nota técnica 23](../mfc/tn023-standard-mfc-resources.md).

AFXRES. H define os símbolos padrão, como `ID_FILE_NEW`, usados pela estrutura e usados especificamente em AFXRES. RC. AFXRES. H também #include WINRES. H, que contém um subconjunto do WINDOWS. H que são necessárias para o C++ Visual gerado. Arquivos RC, bem como AFXRES. RC. Os símbolos definidos em AFXRES. O H está disponível à medida que você edita o arquivo de recursos do aplicativo (MYAPP. RC). Por exemplo, `ID_FILE_NEW` é usado para o item de menu novo arquivo em MYAPP. Recurso de menu do RC. Você não pode alterar ou excluir esses símbolos definidos pelo Framework.

## <a name="_mfcnotes_tn035_including"></a>Incluindo arquivos de cabeçalho adicionais

O aplicativo criado pelo AppWizard inclui apenas dois arquivos de cabeçalho: recurso. H e AFXRES. T. Somente o recurso. H é específico do aplicativo. Talvez seja necessário incluir arquivos de cabeçalho somente leitura adicionais nos seguintes casos:

O arquivo de cabeçalho é fornecido por uma fonte externa ou você deseja compartilhar o arquivo de cabeçalho entre vários projetos ou várias partes do mesmo projeto.

O arquivo de cabeçalho tem formatação e comentários que você não deseja que C++ o Visual altere ou filtre quando salva o arquivo. Por exemplo, talvez você queira preservar #define que usam aritméticas simbólicas, como:

```h
#define RED 0
#define BLUE 1
#define GREEN 2
#define ID_COLOR_BUTTON 1001
#define ID_RED_BUTTON (ID_COLOR_BUTTON + RED)
#define ID_BLUE_BUTTON (ID_COLOR_BUTTON + BLUE)
#define ID_GREEN_BUTTON (ID_COLOR_BUTTON + GREEN)
```

Você pode incluir arquivos de cabeçalho somente leitura adicionais usando o comando **Resource includes** para especificar a instrução #include como uma segunda diretiva de símbolo somente leitura, como em:

```rc
#include "afxres.h"
#include "second.h"
```

O novo diagrama de relação de arquivo agora tem esta aparência:

```Diagram
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

## <a name="sharing-a-header-file-between-two-rc-files"></a>Compartilhando um arquivo de cabeçalho entre dois. Arquivos RC

Talvez você queira compartilhar um arquivo de cabeçalho entre dois. Arquivos RC que estão em projetos diferentes, ou possivelmente o mesmo projeto. Para fazer isso, basta aplicar a técnica de diretivas somente leitura descrita acima para ambos. Arquivos RC. No caso em que os dois. Os arquivos RC são para aplicativos diferentes (projetos diferentes), o resultado é ilustrado no diagrama a seguir:

```Diagram
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

O caso em que o segundo arquivo de cabeçalho é compartilhado por dois. Os arquivos RC no mesmo aplicativo (projeto) são discutidos abaixo.

## <a name="using-multiple-resource-files-in-the-same-project"></a>Usando vários arquivos de recursos no mesmo projeto

O C++ visual e o compilador de recurso dão suporte a vários. Arquivos RC no mesmo projeto por meio de #include de um. Arquivo RC dentro de outro. Vários aninhamentos são permitidos. Há vários motivos para dividir os recursos do projeto em vários. Arquivos RC:

- É mais fácil gerenciar um grande número de recursos entre vários membros da equipe do projeto se você dividir os recursos em vários. Arquivos RC. Se você usar um pacote de gerenciamento de controle do código-fonte para fazer check-out de arquivos e check-in de alterações, dividir os recursos em vários. Os arquivos RC fornecerão um controle mais preciso sobre o gerenciamento de alterações em recursos.

- Se você quiser usar diretivas de pré-processador, como #ifdef, #endif e #define, para partes de seus recursos, será preciso isolá-las em recursos somente leitura que serão compilados pelo compilador de recursos.

- Componente. Os arquivos RC serão carregados e salvos mais rapidamente C++ no Visual do que um composto. Arquivo RC.

- Se você quiser manter um recurso com um editor de texto em um formulário legível, mantenha-o em um. Arquivo RC separado de uma edição Visual C++ .

- Se você precisar manter um recurso definido pelo usuário em um formato de texto ou binário que seja interpretável por outro editor de dados especializado, você deverá mantê-lo em um separado. Arquivo RC para que C++ o Visual não altere o formato para dados hexadecimais. Dos. Os recursos de arquivo WAV (som) no exemplo conceitos avançados do [MFC são um](../overview/visual-cpp-samples.md) bom exemplo.

Você pode #include um segundo. RC nas diretivas de tempo de compilação na caixa de diálogo Set includes:

```h
#include "res\myapp.rc2"  // non-Visual C++ edited resources
#include "second.rc"  // THE SECOND .RC FILE

#include "afxres.rc"  // Standard components
#include "afxprint.rc"  // printing/print preview resources
```

O resultado é ilustrado no diagrama a seguir:

```Diagram
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

Usando diretivas de tempo de compilação, você pode organizar seus C++recursos editáveis e não editáveis em vários. Arquivos RC, nos quais o "mestre" MYAPP. O RC não faz nada, mas #include o outro. Arquivos RC. Se você estiver usando um projeto do C++ Visual Studio. Arquivo MAK, você deve incluir o "mestre". Arquivo RC no projeto para que todos os #include recursos sejam compilados com seu aplicativo.

## <a name="enforcement-of-noneditable-visual-c-files"></a>Imposição de arquivos visuais C++ não editáveis

O RES\MYAPP. AppWizard criado O arquivo RC2 é um exemplo de um arquivo que contém recursos que você *não* deseja ler acidentalmente no Visual C++ e, em seguida, escrevê-los novamente com perda de informações de formatação. Para se proteger contra isso, coloque as seguintes linhas no início do RES\MYAPP. Arquivo RC2:

```rc2
#ifdef APSTUDIO_INVOKED
    #error this file is not editable by Visual C++
#endif //APSTUDIO_INVOKED
```

Quando o C++ Visual compila o. O arquivo RC define `APSTUDIO_INVOKED`, bem como `RC_INVOKED`. Se a estrutura de arquivo AppWizard estiver corrompida e o C++ Visual ler a linha de #error acima, ele relatará um erro fatal e anulará a leitura do. Arquivo RC.

## <a name="managing-symbols-shared-by-multiple-visual-c-edited-rc-files"></a>Gerenciando símbolos compartilhados por vários C++elementos visuais-editados. Arquivos RC

Dois problemas surgem quando você divide seus recursos em vários. Arquivos RC que você deseja editar separadamente no Visual C++:

- Talvez você queira compartilhar os mesmos símbolos em vários. Arquivos RC.

- Você precisa ajudar o Visual C++ a evitar atribuir os mesmos valores numéricos de ID a recursos distintos (símbolos).

O diagrama a seguir ilustra uma organização do. RC e. Arquivos H que lidam com o primeiro problema:

```Diagram
              MYAPP.RC
             /         \
            /           \
MYSTRS.H   / MYSHARED.H  \  MYMENUS.H
     \    /    /      \   \    \
      \  /    /        \   \    \
      MYSTRS.RC         MYMENUS.RC
```

Neste exemplo, os recursos de cadeia de caracteres são mantidos em um arquivo de recurso, MYSTRS. O RC e os menus são mantidos em outro, mymenurs. RC. Alguns símbolos, como para comandos, talvez precisem ser compartilhados entre os dois arquivos. Por exemplo, um ID_TOOLS_SPELL pode ser a ID de comando do menu para o item de ortografia em um menu ferramentas; e também pode ser a ID da cadeia de caracteres do prompt de comando exibido pela estrutura na barra de status da janela principal do aplicativo.

O símbolo de ID_TOOLS_SPELL é mantido no arquivo de cabeçalho compartilhado, myshareed. T. Você mantém esse arquivo de cabeçalho compartilhado manualmente com um editor de texto; O C++ Visual não o edita diretamente. Nos dois arquivos de recurso MYSTRS. RC e mymenurs. RC, você especifica #include MYSHARED. H nas diretivas somente leitura para MYAPP. RC, usando o comando **Resource includes** , conforme descrito anteriormente.

É mais conveniente prever um símbolo que você compartilhará antes de tentar usá-lo para identificar qualquer recurso. Adicione o símbolo ao arquivo de cabeçalho compartilhado e, se você ainda não #include o arquivo de cabeçalho compartilhado nas diretivas somente leitura para o. Arquivo RC, faça isso antes de usar o símbolo. Se você não previu o compartilhamento do símbolo dessa forma, precisará manualmente (usando um editor de texto) mover a instrução #define para o símbolo de, digamos, mymenurs. H para myshareed. H antes de usá-lo em MYSTRS. RC.

Quando você gerencia símbolos em vários. Arquivos RC, você também deve ajudar o C++ visual a evitar atribuir os mesmos valores numéricos de ID a recursos distintos (símbolos). Para qualquer um. Arquivo RC, o C++ Visual incrementalmente atribui IDs em cada um dos quatro domínios de ID. Entre as sessões de edição C++ , o Visual controla a última ID atribuída em cada um dos domínios no arquivo de cabeçalho de símbolo para o. Arquivo RC. Aqui está o que os valores de APS_NEXT são para um vazio (novo). Arquivo RC:

```rc
#define _APS_NEXT_RESOURCE_VALUE  101
#define _APS_NEXT_COMMAND_VALUE   40001
#define _APS_NEXT_CONTROL_VALUE   1000
#define _APS_NEXT_SYMED_VALUE     101
```

`_APS_NEXT_RESOURCE_VALUE` é o próximo valor de símbolo que será usado para um recurso de caixa de diálogo, recurso de menu e assim por diante. O intervalo válido para os valores de símbolo de recurso é de 1 a 0x6FFF.

`_APS_NEXT_COMMAND_VALUE` é o próximo valor de símbolo que será usado para uma identificação de comando. O intervalo válido para os valores de símbolo de comando é 0x8000 para 0xDFFF.

`_APS_NEXT_CONTROL_VALUE` é o próximo valor de símbolo que será usado para um controle de caixa de diálogo. O intervalo válido para os valores de símbolo de controle de caixa de diálogo é de 8 a 0xDFFF.

`_APS_NEXT_SYMED_VALUE` é o próximo valor de símbolo que será emitido quando você atribuir manualmente um valor de símbolo usando o novo comando no navegador de símbolos.

O C++ Visual começa com valores ligeiramente mais altos que o valor legal mais baixo ao criar um novo. Arquivo RC. O AppWizard também irá inicializar esses valores para algo mais apropriado para aplicativos MFC. Para obter mais informações sobre intervalos de valores de ID, consulte a [Nota técnica 20](../mfc/tn020-id-naming-and-numbering-conventions.md).

Agora, sempre que você criar um novo arquivo de recurso, mesmo no mesmo projeto, C++ o Visual definirá os mesmos valores de `_APS_NEXT_`. Isso significa que, se você adicionar, digamos, várias caixas de diálogo de duas diferentes. Arquivos RC, é altamente provável que o mesmo valor de #define seja atribuído a caixas de diálogo diferentes. Por exemplo, IDD_MY_DLG1 na primeira. O arquivo RC pode receber o mesmo número, 101, como IDD_MY_DLG2 em um segundo. Arquivo RC.

Para evitar isso, você deve reservar um intervalo numérico separado para cada um dos quatro domínios de IDs no respectivo. Arquivos RC. Faça isso atualizando manualmente os valores de `_APS_NEXT` em cada um dos. Arquivos RC **antes** de começar a adicionar recursos. Por exemplo, se o primeiro. O arquivo RC usa os valores de `_APS_NEXT` padrão, e você pode desejar atribuir os seguintes valores de `_APS_NEXT` ao segundo. Arquivo RC:

```rc
#define _APS_NEXT_RESOURCE_VALUE  2000
#define _APS_NEXT_COMMAND_VALUE   42000
#define _APS_NEXT_CONTROL_VALUE   2000
#define _APS_NEXT_SYMED_VALUE     2000
```

É claro que ainda é possível que o Visual C++ atribua tantas IDs no primeiro. O arquivo RC que os valores numéricos começam a sobrepor os reservados para o segundo. Arquivo RC. Você deve reservar intervalos suficientemente grandes para que isso não aconteça.

## <a name="managing-dependencies-between-rc-cpp-and-h-files"></a>Gerenciando dependências entre. RC,. CPP e. Arquivos H

Quando o C++ Visual salva um. Arquivo RC, ele também salva as alterações de símbolo no recurso correspondente. Arquivo H. Qualquer um de seus. Arquivos CPP que se referem a recursos no. O arquivo RC deve #include o recurso. Arquivo H, geralmente no arquivo de cabeçalho mestre do seu projeto. Isso leva a um efeito colateral indesejável por causa do gerenciamento de projeto interno do ambiente de desenvolvimento, que examina os arquivos de origem para dependências de cabeçalho. Toda vez que você adiciona um novo símbolo no C++Visual, todos os. Arquivos CPP que #include recurso. H precisaria ser recompilada.

O C++Visual, evita a dependência do recurso. H incluindo o comentário a seguir como a primeira linha do recurso. Arquivo H:

```h
//{{NO_DEPENDENCIES}}
```

O ambiente de desenvolvimento interpreta esse comentário ignorando as alterações no recurso. H para que dependa. Os arquivos CPP não precisarão ser recompilados.

Visual C++ sempre adiciona a linha de comentário//{{NO_DEPENDENCIES}} a um. Arquivo RC quando ele salva o arquivo. Em alguns casos, burlando a dependência de compilação no recurso. H pode levar a erros de tempo de execução não detectados no momento do link. Por exemplo, se você usar o navegador de símbolos para alterar o valor numérico atribuído a um símbolo para um recurso, o recurso não será encontrado corretamente e carregado no tempo de execução do aplicativo se o. O arquivo CPP que faz referência ao recurso não foi recompilado. Nesses casos, você deve recompilar explicitamente qualquer um. Os arquivos CPP que você sabe são afetados pelas alterações de símbolo no recurso. H ou selecione **Recompilar tudo**. Se você tiver a necessidade de alterar com frequência valores de símbolo para um determinado grupo de recursos, provavelmente achará mais conveniente e mais seguro dividir esses símbolos em um arquivo de cabeçalho somente leitura separado, conforme descrito na seção acima, [incluindo arquivos de cabeçalho adicionais](#_mfcnotes_tn035_including).

## <a name="_mfcnotes_tn035_set_includes"></a>Como os C++ conjuntos de gerenciamento Visual incluem informações

Conforme discutido acima, o menu arquivo Set includes permite que você especifique três tipos de informações:

- Arquivo de cabeçalho de símbolo

- Diretivas de símbolo somente leitura

- Diretivas de tempo de compilação

O a seguir descreve como C++ o Visual mantém essas informações em um. Arquivo RC. Você não precisa dessas informações para usar o Visual C++, mas pode melhorar sua compreensão para que você possa usar com mais confiança o recurso Set includes.

Cada um dos três tipos de conjunto acima inclui informações é armazenado no. O arquivo RC em duas formas: (1) como #include ou outras diretivas interpretáveis pelo compilador de recurso e (2) como os recursos de TEXTINCLUDE especiais são interpretados somente pelo Visual C++.

A finalidade do recurso TEXTINCLUDE é armazenar com segurança o conjunto de informações de inclusão em um formulário que seja prontamente apresentável C++na caixa de diálogo **conjunto de inclusões** do Visual. TEXTINCLUDE é um *tipo de recurso* definido pelo C++Visual. O C++ Visual reconhece três recursos de TEXTINCLUDE específicos que têm os números de identificação de recurso 1, 2 e 3:

|ID do recurso do TEXTINCLUDE|O tipo de conjunto inclui informações|
|-----------------------------|--------------------------------------|
|1|Arquivo de cabeçalho de símbolo|
|2|Diretivas de símbolo somente leitura|
|3|Diretivas de tempo de compilação|

Cada um dos três tipos de conjunto inclui informações é ilustrado pelo MYAPP padrão. RC e RESOURCE. Arquivos H criados pelo AppWizard, conforme descrito abaixo. Os tokens adicionais \ 0 e "" entre os blocos BEGIN e END são exigidos pela sintaxe RC para especificar as cadeias de caracteres terminadas com zero e o caractere de aspas duplas, respectivamente.

### <a name="symbol-header-file"></a>Arquivo de cabeçalho de símbolo

A forma das informações de arquivo de cabeçalho de símbolo interpretadas pelo compilador de recurso é simplesmente uma instrução #include:

```rc
#include "resource.h"
```

O recurso TEXTINCLUDE correspondente é:

```rc
1 TEXTINCLUDE DISCARDABLE
BEGIN
    "resource.h\0"
END
```

### <a name="read-only-symbol-directives"></a>Diretivas de símbolo somente leitura

As diretivas de símbolo somente leitura estão incluídas na parte superior de MYAPP. RC no seguinte formato interpretável pelo compilador de recurso:

```rc
#include "afxres.h"
```

O recurso TEXTINCLUDE correspondente é:

```rc
2 TEXTINCLUDE DISCARDABLE
BEGIN
   "#include ""afxres.h""\r\n"
   "\0"
END
```

### <a name="compile-time-directives"></a>Diretivas de tempo de compilação

As diretivas de tempo de compilação são incluídas no final de MYAPP. RC no seguinte formato interpretável pelo compilador de recurso:

```rc
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

A diretiva #ifndef APSTUDIO_INVOKED instrui o Visual C++ a ignorar as diretivas de tempo de compilação.

O recurso TEXTINCLUDE correspondente é:

```rc
3 TEXTINCLUDE DISCARDABLE
BEGIN
"#include ""res\myapp.rc2""  // non-Visual C++ edited resources\r\n"
"\r\n"
"#include ""afxres.rc""  // Standard components\r\n"
"#include ""afxprint.rc""  // printing/print preview resources\r\n"
"\0"
END
```

## <a name="see-also"></a>Veja também

[Notas técnicas por número](../mfc/technical-notes-by-number.md)\
[Observações técnicas por categoria](../mfc/technical-notes-by-category.md)
