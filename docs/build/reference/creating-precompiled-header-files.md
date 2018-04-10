---
title: Criando arquivos de cabeçalho pré-compilado | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-tools
ms.tgt_pltfrm: ''
ms.topic: article
f1_keywords:
- pch
dev_langs:
- C++
helpviewer_keywords:
- precompiled header files, creating
- PCH files, creating
- cl.exe compiler, precompiling code
- .pch files, creating
ms.assetid: e2cdb404-a517-4189-9771-c869c660cb1b
caps.latest.revision: 8
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 09c436d55ad7087d407ba580be0b63286b056898
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="creating-precompiled-header-files"></a>Criando arquivos de cabeçalho pré-compilado
  
Os compiladores C e C++ da Microsoft fornecem opções para pré-compilar qualquer código C ou C++, incluindo código embutido. Usando esse recurso de desempenho, é possível compilar um corpo de código estável, armazenar o estado compilado do código em um arquivo e, durante as compilações subsequentes, combinar o código pré-compilado com código que ainda está em desenvolvimento. Cada compilação subsequente é mais rápida, porque o código estável não precisa ser recompilado.  
  
Este tópico aborda os seguintes assuntos de cabeçalho pré-compilado:  
  
-   [Quando pré-compilar o código-fonte](#when-to-precompile-source-code)  
  
-   [Duas opções para pré-compilar código](#two-choices-for-precompiling-code)  
  
-   [Regras de consistência do cabeçalho pré-compilado](#precompiled-header-consistency-rules)  
  
-   [Regras de consistência para uso por arquivo de cabeçalhos pré-compilados](#consistency-rules-for-per-file-use-of-precompiled-headers)  
  
-   [Regras de consistência para /Yc e /Yu](#consistency-rules-for-yc-and-yu)  
  
-   [Usando cabeçalhos pré-compilados em um projeto](#using-precompiled-headers-in-a-project)  
  
-   [Arquivos PCH no processo de build](#pch-files-in-the-build-process)  
  
-   [Makefile de exemplo para PCH](#sample-makefile-for-pch)  
  
-   [Código de exemplo para PCH](#example-code-for-pch)  
  
Para obter informações de referência sobre as opções de compilador relacionadas aos cabeçalhos pré-compilados, consulte [/Y (cabeçalhos pré-compilados)](../../build/reference/y-precompiled-headers.md).  
  
<a name="when-to-precompile-source-code"></a>  
  
## <a name="when-to-precompile-source-code"></a>Quando pré-compilar o código-fonte  
  
Código pré-compilado é útil durante o ciclo de desenvolvimento para reduzir o tempo de compilação, especialmente se:  
  
-   Você sempre pode usar um corpo grande de código que raramente são alterados.  
  
-   O programa consiste em vários módulos, que usam um conjunto padrão de arquivos de inclusão e as mesmas opções de compilação. Nesse caso, incluem arquivos podem ser pré-compilados em um cabeçalho pré-compilado.  
  
A primeira compilação — que cria o arquivo de cabeçalho pré-compilado (PCH) — demorar um pouco mais do que as compilações subsequentes. Compilações subsequentes podem prosseguir mais rapidamente, incluindo o código pré-compilado.  
  
Você pode pré-compilar programas C e C++. Em programação em C++, é prática comum para separar as informações de classe de interface em arquivos de cabeçalho. Esses arquivos de cabeçalho posteriormente podem ser incluídos nos programas que usam a classe. Pré-compilando esses cabeçalhos, você pode reduzir o tempo que leva um programa para compilar.  
  
> [!NOTE]
>  Embora você possa usar apenas um arquivo de cabeçalho pré-compilado (. pch) por arquivo de origem, você pode usar vários arquivos. pch em um projeto.  
  
<a name="two-choices-for-precompiling-code"></a>  
  
# <a name="two-choices-for-precompiling-code"></a>Duas escolhas para pré-compilar código  
  
Com o Visual C++, você pode pré-compilar o código C ou C++; Você não está limitado a apenas os arquivos de cabeçalho de pré-compilação.  
  
Pré-compilação requer planejamento, mas oferece compilações significativamente mais rápidas se você pré-compilar o código-fonte que não sejam arquivos de cabeçalho simples.  
  
Quando você sabe que os arquivos de origem usam conjuntos comuns de arquivos de cabeçalho, mas não incluem-los na mesma ordem, ou quando você deseja incluir o código-fonte em seu pré-compilação, pré-compile código.  
  
As opções de cabeçalho pré-compilado são [/Yc (criar a arquivo de cabeçalho pré-compilado)](../../build/reference/yc-create-precompiled-header-file.md) e [/Yu (usar pré-compilado arquivo de cabeçalho)](../../build/reference/yu-use-precompiled-header-file.md). Use **/Yc** para criar um cabeçalho pré-compilado. Quando usado com opcional [hdrstop](../../preprocessor/hdrstop.md) pragma, **/Yc** permite que os dois arquivos de cabeçalho de pré-compilação e código-fonte. Selecione **/Yu** para usar um cabeçalho pré-compilado existente na compilação existente. Você também pode usar **/Fp** com o **/Yc** e **/Yu** opções para fornecer um nome alternativo para o cabeçalho pré-compilado.  
  
Os tópicos de referência de opção de compilador para **/Yu** e **/Yc** discutir como acessar essa funcionalidade no ambiente de desenvolvimento.  
  
<a name="precompiled-header-consistency-rules"></a>  
  
## <a name="precompiled-header-consistency-rules"></a>Regras de consistência do cabeçalho pré-compilado  
  
Como arquivos PCH contêm informações sobre o ambiente de máquina, bem como informações de endereço de memória sobre o programa, você deve usar apenas um arquivo PCH no computador em que ele foi criado.  
  
<a name="consistency-rules-for-per-file-use-of-precompiled-headers"></a>  
  
## <a name="consistency-rules-for-per-file-use-of-precompiled-headers"></a>Regras de consistência para uso por arquivo de cabeçalhos pré-compilados

O [/Yu](../../build/reference/yu-use-precompiled-header-file.md) opção de compilador permite que você especifique qual arquivo PCH usar.  
  
Quando você usa um arquivo PCH, o compilador assumirá o mesmo ambiente de compilação — uma que usa as opções do compilador consistente, pragmas e assim por diante, que estava em vigor quando você criou o arquivo PCH, a menos que você especifique o contrário. Se o compilador detecta uma inconsistência, ele emite um aviso e identifica a inconsistência sempre que possível. Esses avisos não indicam necessariamente um problema com o arquivo PCH; eles simplesmente avisá-lo sobre possíveis conflitos. Requisitos de consistência para arquivos PCH são descritos nas seções a seguir.  
  
### <a name="compiler-option-consistency"></a>Consistência de opção de compilador  
  
As opções do compilador podem disparar um aviso de inconsistência ao usar um arquivo PCH:  
  
-   Macros criadas usando o pré-processador (/ D) opção deve ser o mesmo entre a compilação que criou o arquivo PCH e a compilação atual. O estado das constantes definidas não é verificado, mas poderão ocorrer resultados imprevisíveis se essas alteração.  
  
-   Arquivos PCH não funcionam com as opções /E e /EP.  
  
-   Arquivos PCH devem ser criados usando qualquer a gerar informações do navegador (/ FR) opção ou as variáveis locais excluir (/ Fr) opção antes de compilações subsequentes que usam o arquivo PCH podem usar essas opções.  
  
### <a name="c-70-compatible-z7"></a>C compatível com 7.0 (/ Z7)  
  
Se essa opção está em vigor quando o arquivo PCH é criado, as compilações subsequentes que usam o arquivo PCH podem usar as informações de depuração.  
  
Se o C compatível com 7.0 (/ Z7) opção não está em vigor quando o arquivo PCH é criado, as compilações subsequentes que usam o arquivo PCH e /Z7 disparam um aviso. As informações de depuração são colocadas no arquivo. obj atual e símbolos locais definidos no arquivo PCH não estão disponíveis para o depurador.  
  
### <a name="include-path-consistency"></a>Incluir o caminho de consistência  
  
Um arquivo PCH não contém informações sobre o caminho de inclusão estava em vigor quando ela foi criada. Quando você usa um arquivo PCH, o compilador sempre usa o caminho de inclusão especificado na compilação atual.  
  
### <a name="source-file-consistency"></a>Consistência do arquivo de origem  
  
Quando você especificar a opção de arquivo de cabeçalho pré-compilado Use (/Yu), o compilador ignora todas as diretivas de pré-processador (incluindo pragmas) que aparecem no código-fonte que será ser pré-compilados. A compilação especificada por essas diretivas de pré-processador deve ser o mesmo que a compilação usada para a opção de criar a arquivo de cabeçalho pré-compilado (/Yc).  
  
### <a name="pragma-consistency"></a>Consistência de pragma    
  
Pragmas processados durante a criação de um arquivo PCH geralmente afetam o arquivo com o qual o arquivo PCH é usado subsequentemente. O `comment` e `message` pragmas não afetam o restante da compilação.  
  
Esses pragmas afetam apenas o código dentro do arquivo PCH; elas não afetam o código que subsequentemente usa o arquivo PCH:  
  
||||  
|-|-|-|  
|`comment`|`page`|`subtitle`|  
|`linesize`|`pagesize`|`title`|  
|`message`|`skip`||  
  
Esses pragmas são mantidos como parte de um cabeçalho pré-compilado e afetar o restante de uma compilação que usa o cabeçalho pré-compilado:  
  
||||  
|-|-|-|  
|`alloc_text`|`include_alias`|`pack`|  
|`auto_inline`|`init_seg`|`pointers_to_members`|  
|`check_stack`|`inline_depth`|`setlocale`|  
|`code_seg`|`inline_recursion`|`vtordisp`|  
|`data_seg`|`intrinsic`|`warning`|  
|`function`|`optimize`||  
  
<a name="consistency-rules-for-yc-and-yu"></a>  
  
## <a name="consistency-rules-for-yc-and-yu"></a>Regras de consistência para /Yc e /Yu  
  
Quando você usa um cabeçalho pré-compilado criado usando /Yc ou /Yu, o compilador compara o ambiente de compilação atual ao que existia quando você criou o arquivo PCH. Certifique-se de especificar um ambiente consistente com a anterior (usando as opções do compilador consistente, pragmas e assim por diante) para a compilação atual. Se o compilador detecta uma inconsistência, ele emite um aviso e identifica a inconsistência sempre que possível. Esses avisos não indica necessariamente um problema com o arquivo PCH; eles simplesmente avisá-lo sobre possíveis conflitos. As seções a seguir explicam os requisitos de consistência para cabeçalhos pré-compilados.  
  
### <a name="compiler-option-consistency"></a>Consistência de opção de compilador  
  
Esta tabela lista as opções de compilador que podem disparar um aviso de inconsistência ao usar um cabeçalho pré-compilado:  
  
|Opção|Nome|Regra|  
|------------|----------|----------|  
|/D|Definir constantes e macros|Deve ser o mesmo entre a compilação que criou o cabeçalho pré-compilado e a compilação atual. O estado das constantes definidas não é verificado, mas resultados imprevisíveis podem ocorrer se os arquivos dependem dos valores das constantes alterados.|  
|/E ou /EP|Copiar saída de pré-processador para saída padrão|Cabeçalhos pré-compilados não funcionam com a opção /E ou /EP.|  
|/FR ou /FR|Gerar informações do navegador de fonte da Microsoft|Para as opções /Fr e /FR válido com a opção /Yu, eles devem também foram em vigor quando o cabeçalho pré-compilado foi criado. Compilações subsequentes que usam o cabeçalho pré-compilado também geram informações do navegador de fonte. Informações sobre o navegador é colocado em um arquivo. SBR única e é referenciado por outros arquivos da mesma maneira como as informações do CodeView. Você não pode substituir o posicionamento de informações do navegador de fonte.|  
|O lançamento, /GD, /GE, /Gw ou /GW|Opções de protocolo do Windows|Deve ser o mesmo entre a compilação que criou o cabeçalho pré-compilado e a compilação atual. Se essas opções forem diferentes, resultados de uma mensagem de aviso.|  
|/Zi|Gerar informações de depuração completas|Se essa opção está em vigor quando o cabeçalho pré-compilado é criado, as compilações subsequentes que usam a pré-compilação podem usar essas informações de depuração. Se /Zi não estiver em vigor quando o cabeçalho pré-compilado é criado, as compilações subsequentes que usam a pré-compilação e a opção /Zi disparam um aviso. As informações de depuração são colocadas no arquivo do objeto atual e símbolos locais definidos no cabeçalho pré-compilado não estão disponíveis para o depurador.|  
  
> [!NOTE]
>  O recurso de cabeçalho pré-compilado destina-se apenas para uso em arquivos de origem C e C++.  
  
<a name="using-precompiled-headers-in-a-project"></a>  
  
## <a name="using-precompiled-headers-in-a-project"></a>Usando cabeçalhos pré-compilados em um projeto  
  
Seções anteriores apresentam uma visão geral de cabeçalhos pré-compilados: /Yc e /Yu, a opção /Fp e o [hdrstop](../../preprocessor/hdrstop.md) pragma. Esta seção descreve um método para usar as opções de cabeçalho pré-compilado manuais em um projeto; termina com um makefile de exemplo e o código que ele gerencia.  
  
Para outra abordagem usando as opções de cabeçalho pré-compilado manuais em um projeto, estude um makefiles localizados no diretório MFC\SRC que é criado durante a instalação padrão do Visual C++. Esses makefiles adotar uma abordagem semelhante ao apresentado nesta seção, mas usar mais de macros do Microsoft programa manutenção Utility (NMAKE) e oferecem maior controle sobre o processo de compilação.  
  
<a name="pch-files-in-the-build-process"></a>  
  
## <a name="pch-files-in-the-build-process"></a>Arquivos PCH no processo de Build  
  
A base de código de um projeto de software geralmente está contida em vários C ou C++ arquivos de origem, arquivos de objeto, bibliotecas e arquivos de cabeçalho. Normalmente, um makefile coordena a combinação desses elementos em um arquivo executável. A figura a seguir mostra a estrutura de um makefile que usa um arquivo de cabeçalho pré-compilado. Os nomes de macro NMAKE e os nomes de arquivo nesse diagrama são consistentes com aqueles no código de exemplo encontrado na [Makefile de exemplo para PCH](#sample-makefile-for-pch) e [código de exemplo para PCH](#example-code-for-pch).  
  
A figura usa três dispositivos diagramáticas para mostrar o fluxo do processo de compilação. Chamado retângulos representam cada arquivo ou uma macro; as três macros representam um ou mais arquivos. Áreas sombreadas representam cada ação de compilação ou link. As setas mostram quais arquivos e macros são combinadas durante a compilação ou o processo de vinculação.  
  
![Makefile que usa um arquivo de cabeçalho pré-compilado](../../build/reference/media/vc30ow1.gif "estrutura de um Makefile que usa um arquivo de cabeçalho pré-compilado")  
##### <a name="structure-of-a-makefile-that-uses-a-precompiled-header-file"></a>Estrutura de um Makefile que usa um arquivo de cabeçalho pré-compilado  
  
Começando na parte superior do diagrama, STABLEHDRS e limite são macros NMAKE no qual você lista arquivos provavelmente não precisam de recompilação. Esses arquivos são compilados pela cadeia de caracteres de comando  
  
`CL /c /W3 /Yc$(BOUNDRY) applib.cpp myapp.cpp`  
  
somente se o arquivo de cabeçalho pré-compilado (STABLE.pch) não existe ou se você fizer alterações para os arquivos listados em duas macros. Em ambos os casos, o arquivo de cabeçalho pré-compilado conterá código somente de arquivos listados na macro STABLEHDRS. Lista o último arquivo a que ser pré-compilado da macro de limite.  
  
Os arquivos que lista as macros podem ser arquivos de cabeçalho ou arquivos de origem C ou C++. (Um único arquivo PCH não pode ser usado com módulos de C e C++.) Observe que você pode usar o **hdrstop** macro pare de pré-compilação em algum momento dentro do arquivo de limite. Consulte [hdrstop](../../preprocessor/hdrstop.md) para obter mais informações.  
  
Continuar para baixo no diagrama, APPLIB.obj representa o código de suporte usado em seu aplicativo final. É criado a partir de APPLIB.cpp, os arquivos listados na macro UNSTABLEHDRS e pré-compilado código de cabeçalho pré-compilado.  
  
MYAPP.obj representa o aplicativo final. É criado a partir de MYAPP.cpp, os arquivos listados na macro UNSTABLEHDRS e pré-compilado código de cabeçalho pré-compilado.  
  
Por fim, o arquivo executável (MYAPP. EXE) é criado por meio da vinculação de arquivos listados na macro OBJS (APPLIB.obj e MYAPP.obj).  
  
<a name="sample-makefile-for-pch"></a>  
  
## <a name="sample-makefile-for-pch"></a>Makefile de exemplo para PCH  
  
O seguinte makefile usa macros e um! SE! ELSE! Estrutura do comando de fluxo de controle ENDIF para simplificar seu adaptação ao seu projeto.  
  
```NMAKE  
# Makefile : Illustrates the effective use of precompiled  
#            headers in a project  
# Usage:     NMAKE option  
# option:    DEBUG=[0|1]  
#            (DEBUG not defined is equivalent to DEBUG=0)  
#  
OBJS = myapp.obj applib.obj  
# List all stable header files in the STABLEHDRS macro.  
STABLEHDRS = stable.h another.h  
# List the final header file to be precompiled here:  
BOUNDRY = stable.h  
# List header files under development here:  
UNSTABLEHDRS = unstable.h  
# List all compiler options common to both debug and final  
# versions of your code here:  
CLFLAGS = /c /W3  
# List all linker options common to both debug and final  
# versions of your code here:  
LINKFLAGS = /NOD /ONERROR:NOEXE  
!IF "$(DEBUG)" == "1"  
CLFLAGS   = /D_DEBUG $(CLFLAGS) /Od /Zi /f  
LINKFLAGS = $(LINKFLAGS) /COD  
LIBS      = slibce  
!ELSE  
CLFLAGS   = $(CLFLAGS) /Oselg /Gs  
LINKFLAGS = $(LINKFLAGS)  
LIBS      = slibce  
!ENDIF  
myapp.exe: $(OBJS)  
    link $(LINKFLAGS) @<<  
$(OBJS), myapp, NUL, $(LIBS), NUL;  
<<  
# Compile myapp  
myapp.obj  : myapp.cpp $(UNSTABLEHDRS)  stable.pch  
    $(CPP) $(CLFLAGS) /Yu$(BOUNDRY)    myapp.cpp  
# Compile applib  
applib.obj : applib.cpp $(UNSTABLEHDRS) stable.pch  
    $(CPP) $(CLFLAGS) /Yu$(BOUNDRY)    applib.cpp  
# Compile headers  
stable.pch : $(STABLEHDRS)  
    $(CPP) $(CLFLAGS) /Yc$(BOUNDRY)    applib.cpp myapp.cpp  
```  
  
Além de macros STABLEHDRS, limite e UNSTABLEHDRS mostradas na Figura "Estrutura de um Makefile que usa um pré-compilado cabeçalho de arquivo" em [arquivos PCH no processo de compilação](#pch-files-in-the-build-process), este makefile fornece uma macro CLFLAGS e um LINKFLAGS macro. Você deve usar essas macros para listar o compilador e vinculador opções que se aplicam se você criar uma depuração ou a versão final do arquivo executável do aplicativo. Há também uma macro de BIBLIOTECAS onde você lista as bibliotecas requer que seu projeto.  
  
Também usa o makefile! SE! ELSE! ENDIF para detectar se você definir um símbolo de depuração na linha de comando NMAKE:  
  
```NMAKE  
NMAKE DEBUG=[1|0]  
```  
  
Esse recurso torna possível para você usar o mesmo makefile durante o desenvolvimento e para as versões finais de seu programa — use DEBUG = 0 para as versões finais. As linhas de comando a seguir são equivalentes:  
  
```NMAKE  
NMAKE   
NMAKE DEBUG=0  
```  
  
Para obter mais informações sobre makefiles, consulte [referência a NMAKE](../../build/nmake-reference.md). Consulte também [opções do compilador](../../build/reference/compiler-options.md) e [opções do vinculador](../../build/reference/linker-options.md).  
  
<a name="example-code-for-pch"></a>  
  
## <a name="example-code-for-pch"></a>Código de exemplo para PCH  
  
Os seguintes arquivos de origem são usados no makefile descrito em [arquivos PCH no processo de compilação](#pch-files-in-the-build-process) e [Makefile de exemplo para PCH](#sample-makefile-for-pch). Observe que os comentários contêm informações importantes.  
  
```cpp  
// ANOTHER.H : Contains the interface to code that is not  
//             likely to change.  
//  
#ifndef __ANOTHER_H  
#define __ANOTHER_H  
#include<iostream>  
void savemoretime( void );  
#endif // __ANOTHER_H  
```  
  
```cpp  
// STABLE.H : Contains the interface to code that is not likely  
//            to change. List code that is likely to change   
//            in the makefile's STABLEHDRS macro.  
//  
#ifndef __STABLE_H  
#define __STABLE_H  
#include<iostream>  
void savetime( void );  
#endif // __STABLE_H  
```  
  
```cpp  
// UNSTABLE.H : Contains the interface to code that is  
//              likely to change. As the code in a header  
//              file becomes stable, remove the header file  
//              from the makefile's UNSTABLEHDR macro and list  
//              it in the STABLEHDRS macro.  
//  
#ifndef __UNSTABLE_H  
#define __UNSTABLE_H  
#include<iostream.h>  
void notstable( void );  
#endif // __UNSTABLE_H  
```  
  
```cpp
// APPLIB.CPP : This file contains the code that implements  
//              the interface code declared in the header  
//              files STABLE.H, ANOTHER.H, and UNSTABLE.H.  
//  
#include"another.h"  
#include"stable.h"  
#include"unstable.h"  
// The following code represents code that is deemed stable and  
// not likely to change. The associated interface code is  
// precompiled. In this example, the header files STABLE.H and  
// ANOTHER.H are precompiled.  
void savetime( void )  
    { cout << "Why recompile stable code?\n"; }  
void savemoretime( void )  
    { cout << "Why, indeed?\n\n"; }  
// The following code represents code that is still under  
// development. The associated header file is not precompiled.  
void notstable( void )  
    { cout << "Unstable code requires"  
            << " frequent recompilation.\n"; 
    }  
```  
  
```cpp
// MYAPP.CPP : Sample application  
//             All precompiled code other than the file listed  
//             in the makefile's BOUNDRY macro (stable.h in  
//             this example) must be included before the file  
//             listed in the BOUNDRY macro. Unstable code must  
//             be included after the precompiled code.  
//  
#include"another.h"  
#include"stable.h"  
#include"unstable.h"  
int main( void )  
{  
    savetime();  
    savemoretime();  
    notstable();  
}  
```  
    
## <a name="see-also"></a>Consulte também  
[Referência de build do C/C++](../../build/reference/c-cpp-building-reference.md)   
[Opções do Compilador](../../build/reference/compiler-options.md)