---
title: 'TN035: Usando vários arquivos de recurso e arquivos de cabeçalho com o Visual C++'
ms.date: 11/04/2016
f1_keywords:
- vc.resources
helpviewer_keywords:
- resource files, multiple
- TN035
ms.assetid: 1f08ce5e-a912-44cc-ac56-7dd93ad73fb6
ms.openlocfilehash: 0493dd45caf5eb78da435987a4590442a908a5a3
ms.sourcegitcommit: 5cecccba0a96c1b4ccea1f7a1cfd91f259cc5bde
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/01/2019
ms.locfileid: "58772758"
---
# <a name="tn035-using-multiple-resource-files-and-header-files-with-visual-c"></a>TN035: Usando vários arquivos de recurso e arquivos de cabeçalho com o Visual C++

> [!NOTE]
>  A nota técnica a seguir não foi atualizada desde que foi incluído pela primeira vez na documentação online. Como resultado, alguns procedimentos e tópicos podem estar desatualizadas ou incorretas. Para obter as informações mais recentes, é recomendável que você pesquise o tópico de interesse no índice da documentação online.

Essa observação descreve como o editor de recursos do Visual C++ dá suporte a vários arquivos de recurso e arquivos de cabeçalho compartilhados em um único projeto ou compartilhados por vários projetos e como você pode tirar proveito desse suporte. Essa observação responde a essas perguntas:

- Quando você talvez queira dividir um projeto em vários arquivos de recurso e/ou arquivos de cabeçalho, e como você faz isso

- Como compartilhar um cabeçalho comum. Arquivo do H entre dois. Arquivos RC

- Como você divide os recursos do projeto em vários. Arquivos RC

- Como os você (e as ferramentas) gerencia as dependências de compilação entre. RC. CPP, e. Arquivos de H

Você deve estar ciente de que, se você adicionar um arquivo de recurso adicionais ao seu projeto, ClassWizard não reconhecerá os recursos no arquivo adicionado.

Essa observação está estruturada para responder as perguntas acima da seguinte maneira:

- **Visão geral de como o Visual C++ gerencia arquivos de recurso e arquivos de cabeçalho** fornece uma visão geral de como o comando Resource Set Includes no Visual C++ permite que você use vários arquivos de recurso e arquivos de cabeçalho no mesmo projeto.

- **Análise de criado por AppWizard. RC e. Arquivos de H** examina os vários arquivos de cabeçalho e os recursos são usados por um aplicativo criado por AppWizard. Esses arquivos servem como um bom modelo para arquivos de recursos adicionais e arquivos de cabeçalho, que você talvez queira adicionar ao seu projeto.

- **Incluindo arquivos de cabeçalho adicionais** descreve onde você pode querer incluir vários arquivos de cabeçalho e fornece detalhes sobre como fazer isso.

- **Compartilhando um arquivo de cabeçalho entre dois. Arquivos RC** mostra como você pode compartilhar um arquivo de cabeçalho entre vários. Arquivos RC em projetos diferentes, ou talvez no mesmo projeto.

- **Usando vários arquivos de recurso no mesmo projeto** descreve onde deseja dividir seu projeto em vários. RC arquivos e fornece detalhes sobre como fazer isso.

- **Imposição de arquivos não editáveis do Visual C++** descreve como você pode ter certeza de Visual C++ não edite e reformate inadvertidamente um recurso personalizado.

- **Gerenciando os símbolos compartilhados por vários Visual C++ editados. Arquivos RC** descreve como compartilhar os mesmos símbolos entre vários. Arquivos RC e como evitar atribuir valores numéricos de ID duplicados.

- **Gerenciando as dependências entre. RC. CPP, e. Arquivos de H** descreve como o Visual C++ evita a recompilação desnecessária. Arquivos CPP que são dependentes de arquivos de símbolo de recurso.

- **Como o Visual C++ gerencia conjunto inclui informações** fornece detalhes técnicos sobre como o Visual C++ mantém o controle de vários (aninhado). Arquivos RC e vários arquivos de cabeçalho são # include ' d por um. Arquivo RC.

**Visão geral de como o Visual C++ gerencia arquivos de recurso e arquivos de cabeçalho**

Visual C++ gerencia um único. Arquivo de recurso RC e um correspondente. Arquivo de cabeçalho de H como um par acoplado de arquivos. Quando você editar e salvar os recursos em um. Arquivo RC, você indiretamente edita e salva os símbolos em correspondente. Arquivo de H. Embora você possa abrir e editar várias. Arquivos RC por vez (usando a interface do usuário MDI do Visual C++) para qualquer dado. Arquivo RC que você edite indiretamente exatamente um arquivo de cabeçalho correspondente.

**Arquivo de cabeçalho de símbolo**

Por padrão, o Visual C++ nomeia sempre o arquivo de cabeçalho correspondente RESOURCE. H, independentemente do nome do arquivo de recurso (por exemplo, MYAPP. RC). Usando o **recurso inclui** comando da **exibição** menu no Visual C++, você pode alterar o nome deste arquivo de cabeçalho atualizando o arquivo do arquivo de cabeçalho de símbolo no **Set Includes**caixa de diálogo.

**Diretivas de símbolo somente leitura**

Embora o Visual C++ edite apenas um arquivo de cabeçalho para qualquer dado. Arquivo RC, Visual C++ dá suporte a referências a símbolos definidos em arquivos de cabeçalho somente leitura adicionais. Usando o **recurso inclui** comando da **exibição** menu no Visual C++, você pode especificar qualquer número de arquivos de cabeçalho somente leitura adicionais como diretivas de símbolo somente leitura. A restrição "somente leitura" significa que, quando você adiciona um novo recurso nas. Arquivo RC, você pode usar um símbolo definido no arquivo de cabeçalho somente leitura; mas, se você excluir o recurso, o símbolo ainda permanece definido no arquivo de cabeçalho somente leitura. Você não pode alterar o valor numérico atribuído a um símbolo somente leitura.

**Diretivas de tempo de compilação**

Visual C++ também suporta aninhamento de arquivos de recursos, em que um. Arquivo RC é # incluído em outro. Quando você edita um determinado. Arquivo RC usando o Visual C++, todos os recursos no # include ' d arquivos não são visíveis. Mas quando você compila o. Arquivo RC, o # include ' d arquivos também são compilados. Usando o **recurso inclui** comando da **exibição** menu no Visual C++, você pode especificar qualquer número de # include. Arquivos RC como políticas de tempo de compilação.

Observe o que acontece se você ler no Visual C++ um. Arquivo RC #include outro. Arquivo RC *não* especificado como uma diretiva de tempo de compilação. Esta situação pode ocorrer quando você traz para o Visual C++ um. Arquivo RC que você mantivesse anteriormente manualmente com um editor de texto. Quando o Visual C++ lê o # include. Arquivo RC, ele mescla o # include ' d recursos no pai. Arquivo RC. Quando você salva o pai. Arquivo RC, o #include instrução, em vigor, será substituído pelo # include ' d recursos. Se você não quiser que esta mesclagem ocorra, você deve remover o #include instrução do pai. Arquivo RC *anteriores* para lê-lo no Visual C++; usando o Visual C++, em seguida, adicione novamente a mesma #include instrução como uma diretiva de tempo de compilação.

Visual C++ salva em um. Os três tipos de acima do arquivo RC informações Set Includes (arquivo de cabeçalho de símbolo, diretivas de símbolo somente leitura e diretivas de tempo de compilação) em #include diretivas *e* nos recursos de TEXTINCLUDE. Os recursos TEXTINCLUDE, um detalhe de implementação que você normalmente não precisa lidar com, são explicados [como o Visual C++ gerencia conjunto inclui informações](#_mfcnotes_tn035_set_includes).

**Análise de criado por AppWizard. RC e. Arquivos de H**

Examinar o código do aplicativo gerado por AppWizard fornece informações sobre como o Visual C++ gerencia vários arquivos de recurso e arquivos de cabeçalho. Os trechos de código são examinados abaixo são de um aplicativo de MYAPP gerado pelo AppWizard as opções padrão.

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

Você pode exibir essas relações de vários arquivos usando o comando de arquivo do Visual C++ /o conjunto inclui.

MYAPP. RC do arquivo de recurso do aplicativo que você edita usando o Visual C++.

RECURSO. H é o arquivo de cabeçalho específico do aplicativo. É sempre denominado RESOURCE. H por AppWizard, consistente com o padrão do Visual C++ de nomenclatura de arquivo de cabeçalho. O #include para esse arquivo de cabeçalho é a primeira instrução no arquivo de recurso (MYAPP. RC):

```
//Microsoft Visual C++ generated resource script
//
#include "resource.h"
```

RES\MYAPP. RC2 contém recursos que não serão editados pelo Visual C++, mas serão incluídos no final compilado. Arquivo EXE. AppWizard não cria nenhum recurso do gênero por padrão, uma vez que o Visual C++ pode editar todos os recursos padrão, incluindo o recurso de versão (um novo recurso nesta versão). Um arquivo vazio é gerado por AppWizard caso você deseja adicionar seus próprios recursos formatados personalizados para esse arquivo.

Se você usar recursos formatados personalizados, você pode adicioná-los para RES\MYAPP. RC2 e editá-los usando o editor de texto do Visual C++.

AFXRES. RC e AFXPRINT. RC contêm os recursos padrão requeridos por determinados recursos do framework. Como RES\MYAPP. RC2, esses dois arquivos de recurso fornecidos por estrutura são # include no final de MYAPP. RC e elas são especificadas nas diretivas de tempo de compilação da caixa de diálogo conjunto inclui. Assim, você não diretamente exibir ou editar esses recursos de estrutura, enquanto você editar MYAPP. RC no Visual C++, mas eles são compilados no binário do aplicativo. Arquivo RES e final. Arquivo EXE. Para obter mais informações sobre os recursos de estrutura padrão, incluindo procedimentos para modificá-los, consulte [Observação técnica 23](../mfc/tn023-standard-mfc-resources.md).

AFXRES. H define símbolos padrão, tais como `ID_FILE_NEW`, usado pela estrutura e usados especificamente no AFXRES. RC. AFXRES. H também #include WINRES. H, que contém um subconjunto do WINDOWS. H que são necessários para gerado pelo Visual C++. Arquivos RC, bem como AFXRES. RC. Os símbolos definidos em AFXRES. H estão disponíveis conforme você edita o arquivo de recurso do aplicativo (MYAPP. RC). Por exemplo, `ID_FILE_NEW` é usado para o arquivo novo item de menu em MYAPP. Recurso de menu do RC. Você não pode alterar ou excluir esses símbolos definidos pela estrutura.

## <a name="_mfcnotes_tn035_including"></a> Incluindo arquivos de cabeçalho adicionais

O aplicativo criado por AppWizard inclui apenas dois arquivos de cabeçalho: RECURSO. H e AFXRES. H. Somente o recurso. H é específico do aplicativo. Talvez seja necessário incluir arquivos de cabeçalho somente leitura adicionais nos seguintes casos:

O arquivo de cabeçalho é fornecido por uma fonte externa, ou você deseja compartilhar o arquivo de cabeçalho entre vários projetos ou várias partes do mesmo projeto.

O arquivo de cabeçalho tem formatação e os comentários que você não deseja que o Visual C++ alterasse ou filtrasse ao salvar o arquivo. Por exemplo, talvez você queira preservar #Defines que usam a aritmética simbólica, como:

```
#define RED 0
#define BLUE 1
#define GREEN 2
#define ID_COLOR_BUTTON 1001
#define ID_RED_BUTTON (ID_COLOR_BUTTON + RED)
#define ID_BLUE_BUTTON (ID_COLOR_BUTTON + BLUE)
#define ID_GREEN_BUTTON (ID_COLOR_BUTTON + GREEN)
```

Você pode incluir arquivos de cabeçalho somente leitura adicionais usando o **inclui recursos** comando para especificar o #include instrução como uma segunda diretiva de símbolo somente leitura, como em:

```
#include "afxres.h"
#include "second.h"
```

O novo diagrama de relação do arquivo agora é semelhante isso:

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

**Compartilhando um arquivo de cabeçalho entre dois. Arquivos RC**

Talvez você queira compartilhar um arquivo de cabeçalho entre dois. Arquivos RC que estão em diferentes projetos ou, possivelmente, o mesmo projeto. Para fazer isso, basta aplica a técnica de diretivas somente leitura descrita acima para ambos. Arquivos RC. No caso em que os dois. Arquivos RC são de aplicativos diferentes (projetos diferentes), o resultado é ilustrado no diagrama a seguir:

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

Visual C++ e o compilador de recurso dar suporte a várias. Arquivos RC no mesmo projeto nas #include de um. Arquivo RC dentro de outra. O aninhamento múltiplo é permitido. Há várias razões para dividir os recursos do projeto em vários. Arquivos RC:

- É mais fácil de gerenciar um grande número de recursos entre vários membros da equipe de projeto se você dividir os recursos em vários. Arquivos RC. Se você usar um pacote de gerenciamento de controle do código-fonte para fazer check-out de arquivos e fazer check-in de alterações, dividir os recursos em vários. Arquivos RC fornecerá um melhor controle sobre como gerenciar alterações aos recursos.

- Se você quiser usar diretivas de pré-processador, como #ifdef, #endif, e #define, para partes de seus recursos, você deve isolá-las em recursos somente leitura que serão compilados pelo compilador de recurso.

- Componente. Arquivos RC carregará e salvos mais rapidamente no Visual C++ que uma composição. Arquivo RC.

- Se você quiser manter um recurso com um editor de texto em um formato legível por humanos, você deve mantê-lo um. Arquivo RC separado do Visual C++ edita.

- Se você precisar manter um recurso definido pelo usuário em um formato binário ou texto que pode ser interpretado por outro editor de dados especializado, você deve mantê-lo em um separado. Arquivo RC para que Visual C++ não altera o formato para dados hexadecimais. A. Recursos de arquivos WAV (som) no exemplo de conceitos avançados MFC [SPEAKN](../overview/visual-cpp-samples.md) são um bom exemplo.

Você pode #include um segundo. RC nas diretivas de tempo de compilação na caixa de diálogo conjunto inclui:

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

Usando diretivas de tempo de compilação, você pode organizar seus recursos do Visual C++ editáveis e não editáveis em vários. Arquivos RC, onde o "mestre" MYAPP. RC não faz nada, mas #include a outra. Arquivos RC. Se você estiver usando um projeto do Visual C++. Arquivo MAK, em seguida, você deve incluir o "mestre". RC do arquivo no projeto até que todos os o # include ' d recursos são compilados com o seu aplicativo.

**Imposição de arquivos não editáveis do Visual C++**

RES\MYAPP criado por AppWizard. Arquivo RC2 é um exemplo de um arquivo que contém recursos que você *não* deseja ler acidentalmente no Visual C++ e, em seguida, escrevê-lo novamente com perda de informações de formatação. Para proteger contra isso, coloque as seguintes linhas no início do RES\MYAPP. Arquivo RC2:

```
#ifdef APSTUDIO_INVOKED
#error this file is not editable by Visual C++
#endif //APSTUDIO_INVOKED
```

Quando o Visual C++ compila o. Arquivo RC, ele define `APSTUDIO_INVOKED` , bem como `RC_INVOKED`. Se a estrutura do arquivo criado por AppWizard estiver corrompida e o Visual C++ lê a linha #error acima, ele relatará um erro fatal e anulará a leitura dos. Arquivo RC.

**Gerenciando os símbolos compartilhados por vários Visual C++ editados. Arquivos RC**

Dois problemas ocorrem quando você divide seus recursos em vários. Arquivos RC que você deseja editar separadamente no Visual C++:

- Talvez você queira compartilhar os mesmos símbolos entre vários. Arquivos RC.

- Você precisa ajudar a evitar atribuir os mesmos valores numéricos de identificação a recursos distintos (símbolos) do Visual C++.

O diagrama a seguir ilustra uma organização. RC e. Arquivos de H que lida com o primeiro problema:

```
    MYAPP.RC */         \ */           \
MYSTRS.H   / MYSHARED.H  \  MYMENUS.H
\    /    /      \   \    \
\  /    /        \   \    \
    MYSTRS.RC MYMENUS.RC
```

Neste exemplo, os recursos de cadeia de caracteres são mantidos em um arquivo de recurso, MYSTRS. RC e menus são mantidos no outro, MYMENUS. RC. Alguns símbolos, como os comandos, talvez precise ser compartilhado entre os dois arquivos. Por exemplo, um ID_TOOLS_SPELL pode ser a ID de comando de menu para o item de correção ortográfica em um menu de ferramentas. e também pode ser a ID de cadeia de caracteres do prompt de comando exibido pela estrutura na barra de status de janela principal do aplicativo.

O símbolo de ID_TOOLS_SPELL é mantido no arquivo de cabeçalho compartilhado, MYSHARED. H. Manter esse arquivo de cabeçalho compartilhado manualmente com um editor de texto; Visual C++ edita diretamente. No recurso de dois arquivos MYSTRS. RC e MYMENUS. RC, você especifica #include MYSHARED. H nas diretivas somente leitura para MYAPP. RC, usando o **inclui recursos** de comando, conforme descrito anteriormente.

É mais conveniente antecipar um símbolo que você compartilhará antes de tentar usá-lo para identificar qualquer recurso. Adicionar o símbolo para o arquivo de cabeçalho compartilhado e, se você ainda não tiver # include do arquivo de cabeçalho compartilhado nas diretivas somente leitura para o. RC do arquivo, faça isso antes de usar o símbolo. Se você não antecipou compartilhamento do símbolo dessa maneira, você terá que manualmente (usando um editor de texto) mover a #define a instrução para o símbolo de, digamos, MYMENUS. H para MYSHARED. H antes de usá-lo em MYSTRS. RC.

Quando você gerencia os símbolos em vários. Arquivos RC, você também deve ajudar o Visual C++ evitar atribuir os mesmos valores numéricos de identificação a recursos distintos (símbolos). Para qualquer dado. Arquivo RC, Visual C++ atribui adicionalmente IDs em cada um dos quatro domínios de ID. Entre as sessões de edição, Visual C++ mantém controle sobre a última ID atribuída em cada um dos domínios no arquivo de cabeçalho de símbolo para o. Arquivo RC. Aqui está o que os valores de APS_NEXT são para um vazio (novo). Arquivo RC:

```
#define _APS_NEXT_RESOURCE_VALUE  101
#define _APS_NEXT_COMMAND_VALUE   40001
#define _APS_NEXT_CONTROL_VALUE   1000
#define _APS_NEXT_SYMED_VALUE     101
```

`_APS_NEXT_RESOURCE_VALUE` é o próximo valor de símbolo que será usado para um recurso de caixa de diálogo, recurso de menu e assim por diante. O intervalo válido para valores de símbolo de recurso é 1 para 0x6FFF.

`_APS_NEXT_COMMAND_VALUE` é o próximo valor de símbolo que será usado para uma identificação de comando. O intervalo válido de valores de símbolo de comando é 0x8000 para 0xDFFF.

`_APS_NEXT_CONTROL_VALUE` é o próximo valor de símbolo que será usado para um controle de caixa de diálogo. O intervalo válido de valores de símbolo do controle de caixa de diálogo é 8 para 0xDFFF.

`_APS_NEXT_SYMED_VALUE` é o próximo valor de símbolo que será emitido quando você atribuir manualmente um valor de símbolo usando o comando novo no navegador de símbolos.

O Visual C++ inicia com valores ligeiramente maiores que o menor valor válido quando criar um novo. Arquivo RC. O AppWizard também inicializará esses valores para algo mais adequado para aplicativos MFC. Para obter mais informações sobre intervalos de valores de ID, consulte [nota técnica 20](../mfc/tn020-id-naming-and-numbering-conventions.md).

Agora, sempre que você cria um novo arquivo de recursos, até mesmo no mesmo projeto, o Visual C++ define os mesmos `_APS_NEXT_` valores. Isso significa que se você adicionar, por exemplo, várias caixas de diálogo em duas diferentes. Arquivos RC, é muito provável que o mesmo #define valor será atribuído caixas de diálogo diferentes. Por exemplo, IDD_MY_DLG1 no primeiro. Arquivo RC pode receber o mesmo número, 101, como IDD_MY_DLG2 em um segundo. Arquivo RC.

Para evitar isso, você deve reservar um intervalo numérico separado para cada um dos quatro domínios de IDs no respectivo. Arquivos RC. Fazer isso manualmente atualizando o `_APS_NEXT` valores em cada um a. Arquivos RC **antes de** você começar a adicionar recursos. Por exemplo, se o primeiro. Arquivo RC usa o padrão `_APS_NEXT` valores, em seguida, você talvez queira atribuir os seguintes `_APS_NEXT` valores para o segundo. Arquivo RC:

```
#define _APS_NEXT_RESOURCE_VALUE  2000
#define _APS_NEXT_COMMAND_VALUE   42000
#define _APS_NEXT_CONTROL_VALUE   2000
#define _APS_NEXT_SYMED_VALUE     2000
```

É claro, ainda é possível que o Visual C++ atribua tantas IDs no primeiro. Arquivo RC que os valores numéricos comecem a sobrepor aqueles reservado para o segundo. Arquivo RC. Você deve reservar intervalos suficientemente grandes para que isso não acontece.

**Gerenciando as dependências entre. RC. CPP, e. Arquivos de H**

Quando o Visual C++ salva um. Arquivo RC, ele também salva as alterações de símbolo para o recurso correspondente. Arquivo de H. Qualquer um dos seus. Os arquivos CPP que se referem a recursos na. Arquivo RC deve #include do recurso. Arquivo H, geralmente no arquivo de cabeçalho mestre do seu projeto. Isso leva a um efeito colateral indesejado devido ao gerenciamento de projetos interno do ambiente de desenvolvimento que verifica a existência de arquivos de origem para dependências do cabeçalho. Sempre que você adicionar um novo símbolo no Visual C++, todos os. Arquivo CPP #include recurso. H precisariam ser recompilado.

O Visual C++ contorna a dependência no recurso. H, incluindo o seguinte comentário como a primeira linha do recurso. Arquivo do H:

```
//{{NO_DEPENDENCIES}}
```

O ambiente de desenvolvimento interpreta este comentário ignorando as alterações ao recurso. Portanto, que é dependente de H. Arquivos CPP não precisarão ser recompilados.

O Visual C++ sempre adiciona a //{{no_dependencies}}}} comentário de linha para um. Arquivo RC quando salva o arquivo. Em alguns casos, evitando a dependência de compilação no recurso. H pode levar a erros de tempo de execução não detectados em tempo de vinculação. Por exemplo, se você usar o navegador do símbolo para alterar o valor numérico atribuído a um símbolo para um recurso, o recurso de não ser corretamente encontrado e carregado em caso de tempo de execução do aplicativo a. Arquivo CPP referindo-se para o recurso não é recompilado. Nesses casos, você deve recompilar explicitamente qualquer. Os arquivos CPP que você sabe que são afetados pelas alterações de símbolo no recurso. H ou select **Rebuild All**. Se você tiver a necessidade de alterar com frequência de valores de símbolo para um determinado grupo de recursos, você provavelmente achará mais conveniente e seguro quebrar esses símbolos em um arquivo de cabeçalho somente leitura separado, conforme descrito na seção acima [incluindo Arquivos de cabeçalho adicionais](#_mfcnotes_tn035_including).

## <a name="_mfcnotes_tn035_set_includes"></a> Como o Visual C++ gerencia conjunto inclui informações**

Como discutido acima, o comando Set Includes do menu Arquivo permite que você especifique três tipos de informações:

- Arquivo de cabeçalho de símbolo

- Diretivas de símbolo somente leitura

- Diretivas de tempo de compilação

A seguir descreve como o Visual C++ mantém essas informações em um. Arquivo RC. Você não precisa dessas informações para usar o Visual C++, mas ele pode aprimorar seu entendimento para que a maneira mais confiável, você pode usar o recurso de conjunto inclui.

Cada um dos três tipos acima de Set Includes information é armazenada na. Arquivo RC de duas formas: (1) como #include ou outras diretivas que é interpretadas pelo compilador de recurso e (2) como recursos especiais de TEXTINCLUDE que é interpretados somente pelo Visual C++.

A finalidade do recurso TEXTINCLUDE é armazenar com segurança as informações do conjunto Include em um formulário que é prontamente apresentável no Visual C++ **Set Includes** caixa de diálogo. TEXTINCLUDE é um *tipo de recurso* definido pelo Visual C++. Visual C++ reconhece três recursos específicos do TEXTINCLUDE que têm o recurso de números de identificação 1, 2 e 3:

|ID do recurso TEXTINCLUDE|Tipo de Set Includes information|
|-----------------------------|--------------------------------------|
|1|Arquivo de cabeçalho de símbolo|
|2|Diretivas de símbolo somente leitura|
|3|Diretivas de tempo de compilação|

Cada um dos três tipos de Set Includes information é ilustrada pelo padrão MYAPP. RC e RESOURCE. Arquivos de H criados pelo AppWizard, conforme descrito abaixo. O \0 extra e "" tokens entre blocos BEGIN e END são necessários pela sintaxe do RC para especificar zero cadeias de caracteres terminadas e o caractere de aspas duplas, respectivamente.

## <a name="symbol-header-file"></a>Arquivo de cabeçalho de símbolo

A forma das informações do arquivo de cabeçalho do símbolo interpretadas pelo compilador de recurso é simplesmente um #include instrução:

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

## <a name="read-only-symbol-directives"></a>Diretivas de símbolo somente leitura

Diretivas de símbolo somente leitura são incluídas na parte superior de MYAPP. RC no formulário a seguir que é interpretado pelo compilador de recurso:

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

## <a name="compile-time-directives"></a>Diretivas de tempo de compilação

As diretivas de tempo de compilação são incluídas no final de MYAPP. RC no formulário a seguir que é interpretado pelo compilador de recurso:

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

A diretiva do #ifndef APSTUDIO_INVOKED instrui o Visual C++ para ignorar as diretivas de tempo de compilação.

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

## <a name="see-also"></a>Consulte também

[Observações técnicas por número](../mfc/technical-notes-by-number.md)<br/>
[Observações técnicas por categoria](../mfc/technical-notes-by-category.md)
