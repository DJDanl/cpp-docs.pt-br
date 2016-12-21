---
title: "Erro fatal C1083 | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "error-reference"
f1_keywords: 
  - "C1083"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C1083"
ms.assetid: 97e52df3-e79c-4f85-8f1e-bbd1057d55e7
caps.latest.revision: 23
caps.handback.revision: 23
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro fatal C1083
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Mensagem Não é possível abrir o arquivo de tipos de arquivo: 'arquivo'  
  
 O compilador gera um erro C1083 quando não pode localizar um arquivo. Estes são os motivos comuns pelos quais o compilador gera esse erro.  
  
 **O nome de arquivo especificado está errado**  
  
 O nome de um arquivo pode ter sido digitado incorretamente. Por exemplo,  
  
```cpp  
#include <algorithms.h>  
```  
  
 pode não encontrar o arquivo desejado. Há um arquivo de cabeçalho da Biblioteca C++ Padrão chamado algorithms que não tem a extensão de nome de arquivo .h. Ele não seria encontrado por essa diretiva `include`. Para corrigir esse problema, verifique se o nome de arquivo correto foi digitado.  
  
 Certos cabeçalhos da biblioteca CRT estão localizados em um subdiretório do diretório de inclusão padrão. Por exemplo, para incluir sys\types.h, você deve incluir o nome do subdiretório sys na diretiva include:  
  
 `#include <sys\types.h>`  
  
 **O arquivo não está incluído no caminho de pesquisa do compilador**  
  
 O compilador não pode encontrar o arquivo usando as regras de pesquisa que são indicadas por uma diretiva `include` ou `import`. Por exemplo, um nome de arquivo de cabeçalho que está entre aspas  
  
 `#include "myincludefile.h"`  
  
 diz para o compilador procurar o arquivo no mesmo diretório que contém o arquivo de origem primeiro e depois procurar outros locais especificados pelo ambiente de compilação. Se as aspas contiverem um caminho absoluto, o compilador procurará somente o arquivo nesse local. Se as aspas contiverem um caminho relativo, o compilador procurará o arquivo no diretório relativo ao diretório de origem. Se o nome estiver entre colchetes angulares  
  
 `#include <stdio.h>`  
  
 o compilador seguirá um caminho de pesquisa definido pelo ambiente de compilação, a **/i** opção de compilador, o **/X** opção de compilador e o **INCLUIR** variável de ambiente. Para obter mais informações, incluindo detalhes específicos sobre a ordem de pesquisa usadas para localizar um arquivo, consulte [#include (C/C++) de diretiva](../../preprocessor/hash-include-directive-c-cpp.md) e [#import diretiva](../Topic/%23import%20Directive%20\(C++\).md).  
  
 Mesmo quando os arquivos de cabeçalho são listados em **Solution Explorer** como parte de um projeto, os arquivos só são encontrados pelo compilador quando são chamados por um `include` ou `import` diretiva e localizados em um caminho de pesquisa de diretório. Tipos diferentes de compilações podem usar caminhos de pesquisa diferentes. O **/X** opção de compilador pode ser usada para excluir diretórios do caminho de pesquisa de arquivo de inclusão. Isso permite que diferentes compilações usem arquivos de inclusão diferentes de mesmo nome, mas são mantidos em diretórios diferentes. Essa é uma alternativa à compilação condicional usando comandos do pré-processador. Para obter mais informações sobre o **/X** opção de compilador, consulte [/X (ignorar caminhos de inclusão padrão)](../../build/reference/x-ignore-standard-include-paths.md).  
  
 Quando o compilador é invocado na linha de comando, variáveis de ambiente são geralmente usadas para especificar caminhos de pesquisa. Se o caminho de pesquisa descrito pelo **INCLUIR** variável de ambiente não estiver definida corretamente, é gerado um erro C1083. Para obter mais informações sobre como usar variáveis de ambiente, consulte [como: usar variáveis de ambiente em uma compilação](../Topic/How%20to:%20Use%20Environment%20Variables%20in%20a%20Build.md).  
  
 Para corrigir esse problema, corrija o caminho que o compilador usa para procurar o arquivo incluído ou importado. Um novo projeto usa caminhos de pesquisa padrão. Talvez seja preciso modificar o caminho para adicionar um diretório para seu projeto. Se você está compilando na linha de comando, defina o **INCLUIR** variável de ambiente ou o **/i** opção de compilador para especificar o caminho do arquivo. Para definir o caminho do diretório de inclusão no Visual Studio, abra o projeto **páginas de propriedade** caixa de diálogo caixa, expanda **Propriedades de configuração** e **diretórios VC + +**, e, em seguida, edite o **diretórios de inclusão** valor. Para obter mais informações sobre os diretórios por usuário e por projeto pesquisados pelo compilador no Visual Studio, consulte [página de propriedade de diretórios VC + +](../../ide/vcpp-directories-property-page.md). Para obter mais informações sobre o **/i** opção de compilador, consulte [/I (diretórios de inclusão adicionais)](../../build/reference/i-additional-include-directories.md).  
  
 **A versão incorreta de um nome de arquivo está incluída**  
  
 Um erro C1083 também pode indicar que a versão incorreta de um arquivo foi incluída. Por exemplo, uma compilação poderia incluir a versão incorreta de um arquivo que tem uma diretiva `include` para um arquivo de cabeçalho não destinado a essa compilação. Quando o arquivo de cabeçalho não é localizado, o compilador gera um erro C1083. A correção desse problema é usar o arquivo correto, não adicionar o arquivo de cabeçalho ou diretório à compilação.  
  
 **Os cabeçalhos pré-compilados ainda não foram pré-compilados**  
  
 Quando um projeto é configurado para usar cabeçalhos pré-compilados, os arquivos .pch relevantes precisam ser criados de forma que os arquivos que usam o conteúdo do cabeçalho possam ser compilados. Por exemplo, o arquivo stdafx.cpp é criado automaticamente no diretório do projeto para novos projetos MFC. Compile esse arquivo primeiro para criar os arquivos de cabeçalho pré-compilados. (No design de processo de compilação típico, isso é feito automaticamente.) Para obter mais informações, consulte [Criando arquivos de cabeçalho pré-compilado](../../build/reference/creating-precompiled-header-files.md).  
  
 **Causas adicionais**  
  
-   O arquivo usa código gerenciado, mas a opção de compilador **/clr** não for especificado. Para obter mais informações, consulte [/clr (Common Language Runtime Compilation)](../../build/reference/clr-common-language-runtime-compilation.md).  
  
-   O arquivo é compilado usando outro **/Analyze** configuração de opção de compilador que é usada para pré-compilar os cabeçalhos. (Quando os cabeçalhos para um projeto são pré-compilados, deve usar a mesma **/Analyze** configurações.) Para obter mais informações, consulte [/Analyze (análise de código)](../../build/reference/analyze-code-analysis.md).  
  
-   O arquivo, o diretório ou o disco é somente leitura.  
  
-   As permissões de acesso para o arquivo ou diretório não foram concedidas.  
  
-   Não há identificadores de arquivo suficientes. Feche alguns aplicativos e recompile-os. Essa condição é incomum em circunstâncias normais. No entanto, pode ocorrer quando projetos grandes são compilados em um computador com memória física limitada.  
  
 O exemplo a seguir gera um erro C1083.  
  
```  
// C1083.cpp  
// compile with: /c  
#include "test.h"   // C1083 test.h does not exist  
#include "stdio.h"   // OK  
```  
  
 Para obter informações sobre como compilar projetos C/C++ no IDE ou na linha de comando e informações sobre como definir variáveis de ambiente, consulte [Compilando programas C/C++](../../build/building-c-cpp-programs.md).
 
 ## <a name="see-also"></a>Consulte também
 [Propriedades MSBuild](MSBuild%20Properties.md)