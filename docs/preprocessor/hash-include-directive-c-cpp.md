---
title: "Diretiva #include (C/C++) | Microsoft Docs"
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
  - "#include"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Diretiva #include"
  - "diretiva include (#include)"
  - "pré-processador, Diretivas ()"
ms.assetid: 17067dc0-8db1-4f2d-b43e-ec12ecf83238
caps.latest.revision: 15
caps.handback.revision: 12
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Diretiva #include (C/C++)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Informa o pré\-processador para tratar o conteúdo de um arquivo especificado como se ele aparecesse no programa de origem no ponto onde a política aparece.  
  
## Sintaxe  
  
```  
  
      #include  "path-spec"  
#include  <path-spec>  
```  
  
## Comentários  
 É possível organizar definições de constante e de macro em arquivos de inclusão e, em seguida, usar políticas `#include` para adicionar essas definições a qualquer arquivo de origem.  Os arquivos de inclusão também são úteis para incorporar declarações de variáveis externas e tipos de dados complexos.  Os tipos podem ser definidos e nomeados somente uma vez em um arquivo de inclusão criado para essa finalidade.  
  
 `path-spec` é um nome de arquivo que pode, opcionalmente, ser precedido por uma especificação de diretório.  O nome do arquivo deve nomear um arquivo existente.  A sintaxe de `path-spec` depende do sistema operacional em que o programa é compilado.  
  
 Para obter informações sobre como referenciar assemblies no aplicativo C\+\+ compilado usando [\/clr](../build/reference/clr-common-language-runtime-compilation.md), consulte [\#using](../preprocessor/hash-using-directive-cpp.md).  
  
 As duas formas de sintaxe causam a substituição da política pelo conteúdo inteiro do arquivo de inclusão especificado.  A diferença entre as duas formas é a ordem em que o pré\-processador procura por arquivos de cabeçalho quando o caminho é especificado de forma incompleta.  A tabela a seguir mostra a diferença entre as duas formas de sintaxe.  
  
|Forma de sintaxe|Ação|  
|----------------------|----------|  
|Forma entre aspas|O pré\-processador pesquisa por arquivos de inclusão nesta ordem:<br /><br /> 1.  No mesmo diretório do arquivo que contém a instrução `#include`.<br />2.  Nos diretórios dos arquivos de inclusão abertos atualmente, na ordem inversa da qual foram abertos.  A pesquisa começará no diretório do arquivo de inclusão pai e continuará para cima até os diretórios de qualquer arquivo de inclusão avô.<br />3.  Ao longo do caminho que é especificado por cada opção do compilador \/I.<br />4.  Ao longo dos caminhos que são especificados pela variável de ambiente INCLUDE.|  
|Forma de colchete angular|O pré\-processador pesquisa por arquivos de inclusão nesta ordem:<br /><br /> 1.  Ao longo do caminho que é especificado por cada opção do compilador \/I.<br />2.  Quando a compilação ocorre na linha de comando, ao longo dos caminhos que são especificados pela variável de ambiente INCLUDE.|  
  
 O pré\-processador para de pesquisar assim que encontra um arquivo com o nome especificado.  Se você delimitar uma especificação de caminho completa, não ambígua, para o arquivo de inclusão entre aspas duplas \(" "\), o pré\-processador pesquisará apenas essa especificação de caminho e ignorará os diretórios padrão.  
  
 Se o nome do arquivo que estiver dentro das aspas duplas for uma especificação incompleta do caminho, o pré\-processador primeiro pesquisará no diretório do arquivo “pai”.  Arquivo pai é o arquivo que contém a política `#include`.  Por exemplo, se você incluir um arquivo chamado `file2` em um arquivo chamado `file1`, `file1` será o arquivo pai.  
  
 Os arquivos de inclusão podem ser "aninhados", ou seja, uma política `#include` pode aparecer em um arquivo denominado por outra política `#include`.  Por exemplo, `file2` poderia incluir `file3`.  Nesse caso, `file1` ainda deve ser o pai de `file2`, mas seria "avô" de `file3`.  
  
 Ao incluir os arquivos que estão aninhados e ao compilar na linha de comando, a pesquisa de diretório começa com os diretórios do arquivo pai e depois continua pelos diretórios dos arquivos avô.  Ou seja, a pesquisa inicia relativa ao diretório que contém a fonte que está sendo processada atualmente.  Se o arquivo não for encontrado, a pesquisa muda para os diretórios especificados pela opção do compilador \/I.  Por fim, os diretórios que são especificados pela variável de ambiente INCLUDE são pesquisados.  
  
 No ambiente de desenvolvimento, a variável de ambiente INCLUDE é ignorada.  Para obter informações sobre como definir os diretórios procurados para os arquivos de inclusão — essas informações também se aplicam à variável de ambiente LIB — consulte [VC\+\+ Directories, Projects, Options Dialog Box](http://msdn.microsoft.com/pt-br/e027448b-c811-4c3d-8531-4325ad3f6e02).  
  
 Este exemplo mostra a inclusão de arquivo usando os colchetes angulares:  
  
```  
#include <stdio.h>  
```  
  
 Este exemplo adiciona o conteúdo do arquivo chamado STDIO.H ao programa de origem.  Os colchetes angulares fazem com que o pré\-processador procure nos diretórios especificados pela variável de ambiente INCLUDE por STDIO.H, e depois procure nos diretórios especificados pela opção do compilador \/I.  
  
 O exemplo a seguir mostra a inclusão de arquivo usando a forma entre aspas:  
  
```  
#include "defs.h"  
```  
  
 Este exemplo adiciona o conteúdo do arquivo especificado por DEFS.H para o programa de origem.  As aspas significam que o pré\-processador pesquisa primeiro no diretório que contém o arquivo de origem pai.  
  
 O aninhamento dos arquivos de inclusão pode continuar até 10 níveis.  Quando o `#include` aninhado for processado, o pré\-processador continuará a inserir o arquivo de inclusão delimitador no arquivo de código\-fonte original.  
  
 **Específico da Microsoft**  
  
 Para localizar os arquivos de origem que podem ser incluídos, o pré\-processador primeiro procura nos diretórios especificados pela opção do compilador \/I.  Se a opção \/I não estiver presente ou falhar, o pré\-processador usará a variável de ambiente INCLUDE para localizar os arquivos de inclusão entre colchetes angulares.  A variável de ambiente INCLUDE e a opção do compilador \/I podem conter vários caminhos separados por ponto\-e\-vírgula \(;\).  Se mais de um diretório aparecer como parte da opção \/I ou dentro da variável de ambiente INCLUDE, o pré\-processador procurará por eles na ordem em que aparecem.  
  
 Por exemplo, o comando  
  
```  
CL /ID:\MSVC\INCLUDE MYPROG.C  
```  
  
 faz com que o pré\-processador procure no diretório D:\\MSVC\\INCLUDE\\ os arquivos de inclusão, como STDIO.H.  Os comandos  
  
```  
SET INCLUDE=D:\MSVC\INCLUDE  
CL MYPROG.C  
```  
  
 têm o mesmo efeito.  Quando ambos os conjuntos de pesquisas falham, um erro fatal de compilador é gerado.  
  
 Se o nome de arquivo for totalmente especificado para um arquivo de inclusão que possui um caminho que inclui dois\-pontos \(por exemplo, F:\\MSVC\\SPECIAL\\INCL\\TEST.H\), o pré\-processador segue o caminho.  
  
 Para os arquivos de inclusão especificados como `#include` "`path-spec`", a pesquisa de diretório começa com os diretórios do arquivo pai e continua pelos diretórios dos arquivos avô.  Ou seja, a pesquisa inicia relativa ao diretório que contém o arquivo de código\-fonte que contém a política `#include` que está sendo processada.  Se não houver nenhum arquivo avô e o arquivo não tiver sido encontrado, a pesquisa continua como se o nome do arquivo estivesse dentro de colchetes.  
  
 **FIM de Específico da Microsoft**  
  
## Consulte também  
 [Diretivas de pré\-processador](../preprocessor/preprocessor-directives.md)