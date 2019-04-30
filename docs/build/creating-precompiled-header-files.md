---
title: Arquivos de cabeçalho pré-compilado
ms.date: 12/10/2018
f1_keywords:
- pch
helpviewer_keywords:
- precompiled header files, creating
- PCH files, creating
- cl.exe compiler, precompiling code
- .pch files, creating
ms.assetid: e2cdb404-a517-4189-9771-c869c660cb1b
ms.openlocfilehash: 5afda50c43f93baa2d73e6afb68f436560c3243e
ms.sourcegitcommit: c6f8e6c2daec40ff4effd8ca99a7014a3b41ef33
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/24/2019
ms.locfileid: "64341755"
---
# <a name="precompiled-header-files"></a>Arquivos de cabeçalho pré-compilado

Quando você cria um novo projeto no Visual Studio, uma *arquivo de cabeçalho pré-compilado* denominado "pch. h" é adicionado ao projeto. (Em versões anteriores do Visual Studio, o arquivo foi chamado "Stdafx. h".) A finalidade do arquivo é acelerar o processo de compilação. Qualquer cabeçalho estável arquivos, por exemplo cabeçalhos da biblioteca padrão como `<vector>`, devem ser incluídos aqui. O cabeçalho pré-compilado é compilado somente quando ele ou quaisquer arquivos que ele inclui, são modificados. Se você só pode fazer alterações no código-fonte seu projeto, a compilação ignorará a compilação para o cabeçalho pré-compilado. 

São as opções do compilador para cabeçalhos pré-compilados [/Y](reference/y-precompiled-headers.md). Nas páginas de propriedades do projeto, as opções estão localizadas em **propriedades de configuração > C/C++ > cabeçalhos pré-compilados**. Você pode optar por não usar cabeçalhos pré-compilados, e você pode especificar o cabeçalho de nome de arquivo e o nome e caminho do arquivo de saída. 

## <a name="custom-precompiled-code"></a>Código pré-compilado personalizado

Para projetos grandes que levam um tempo significativo para compilar, você talvez queira considerar a criação de arquivos personalizados de pré-compilados. Os compiladores C e C++ da Microsoft fornecem opções para pré-compilar qualquer código C ou C++, incluindo código embutido. Usando esse recurso de desempenho, é possível compilar um corpo de código estável, armazenar o estado compilado do código em um arquivo e, durante as compilações subsequentes, combinar o código pré-compilado com código que ainda está em desenvolvimento. Cada compilação subsequente é mais rápida, porque o código estável não precisa ser recompilado.

## <a name="when-to-precompile-source-code"></a>Quando pré-compilar o código-fonte

Código pré-compilado é útil durante o ciclo de desenvolvimento para reduzir o tempo de compilação, especialmente se:

- Você sempre pode usar uma grande quantidade de código que muda com pouca frequência.

- Seu programa consiste em vários módulos, todos os que usam um conjunto padrão de arquivos de inclusão e as mesmas opções de compilação. Nesse caso, todos incluem arquivos podem ser pré-compilados em um cabeçalho pré-compilado.

A primeira compilação — aquele que cria o arquivo de cabeçalho pré-compilado (PCH) — demora um pouco mais do que as compilações subsequentes. As compilações subsequentes podem prosseguir mais rapidamente, incluindo o código pré-compilado.

Você pode pré-compilar programas em C e C++. Na programação do C++, é prática comum para separar as informações de interface de classe em arquivos de cabeçalho. Esses arquivos de cabeçalho mais tarde podem ser incluídos em programas que usam a classe. Por meio da pré-compilação esses cabeçalhos, você pode reduzir o tempo que um programa necessário para compilar.

> [!NOTE]
> Embora você possa usar apenas um arquivo de cabeçalho pré-compilado (. pch) por arquivo de origem, você pode usar vários arquivos. pch em um projeto.

## <a name="two-choices-for-precompiling-code"></a>Duas escolhas para pré-compilar código

Com o Visual C++, você pode pré-compilar qualquer código C ou C++; Você não está limitado a pré-compilar somente os arquivos de cabeçalho.

Pré-compilação requer um planejamento, mas oferece compilações significativamente mais rápidas se você pré-compilar o código-fonte que não sejam arquivos de cabeçalho simples.

Quando você sabe que seus arquivos de origem usam conjuntos de arquivos de cabeçalho comuns, mas não incluem-los na mesma ordem, ou quando você deseja incluir o código-fonte no seu pré-compilação pré-compile o código.

São as opções de cabeçalho pré-compilado [/Yc (criar a arquivo de cabeçalho pré-compilado)](reference/yc-create-precompiled-header-file.md) e [/Yu (usar arquivo de cabeçalho pré-compilado)](reference/yu-use-precompiled-header-file.md). Use **/Yc** para criar um cabeçalho pré-compilado. Quando usado com opcional [hdrstop](../preprocessor/hdrstop.md) pragma, **/Yc** permite que você pré-compila os dois arquivos de cabeçalho e o código-fonte. Selecione **/Yu** para usar um cabeçalho pré-compilado existente na compilação existente. Você também pode usar **/Fp** com o **/Yc** e **/Yu** opções para fornecer um nome alternativo para o cabeçalho pré-compilado.

Os tópicos de referência de opção de compilador para **/Yu** e **/Yc** discutem como acessar essa funcionalidade no ambiente de desenvolvimento.

## <a name="precompiled-header-consistency-rules"></a>Regras de consistência do cabeçalho pré-compilado

Como os arquivos PCH contêm informações sobre o ambiente de máquina, bem como informações de endereço de memória sobre o programa, você deve usar apenas um arquivo PCH na máquina onde ele foi criado.

## <a name="consistency-rules-for-per-file-use-of-precompiled-headers"></a>Regras de consistência para uso por arquivo de cabeçalhos pré-compilados

O [/Yu](reference/yu-use-precompiled-header-file.md) opção de compilador permite que você especifique qual arquivo PCH usar.

Quando você usa um arquivo PCH, o compilador pressupõe que o mesmo ambiente de compilação — uma que usa as opções do compilador consistente, pragmas e assim por diante — que estava em vigor quando você criou o arquivo PCH, a menos que você especifique de outra forma. Se o compilador detecta uma inconsistência, ele emite um aviso e identifica a inconsistência, sempre que possível. Esses avisos não indicam necessariamente um problema com o arquivo PCH; eles simplesmente avisá-lo sobre possíveis conflitos. Requisitos de consistência para arquivos de PCH são descritos nas seções a seguir.

### <a name="compiler-option-consistency"></a>Consistência de opção de compilador

As opções do compilador podem disparar um aviso de inconsistência ao usar um arquivo PCH:

- Macros criadas usando o pré-processador (/ 1!d) opção deve ser o mesmo entre a compilação que criou o arquivo PCH e a compilação atual. O estado das constantes definidas não é verificado, mas poderão ocorrer resultados imprevisíveis se eles alterar.

- Arquivos PCH não funcionam com as opções /E e /EP.

- Arquivos PCH devem ser criados usando qualquer um da gerar informações do navegador (/ FR) opção ou excluir variáveis locais (/ Fr) opção antes das compilações subsequentes que usam o arquivo PCH podem usar essas opções.

### <a name="c-70-compatible-z7"></a>C 7.0-Compatible (/ Z7)

Se essa opção está em vigor quando o arquivo PCH é criado, as compilações subsequentes que usam o arquivo PCH podem usar as informações de depuração.

Se o C 7.0-Compatible (/ Z7) opção não está em vigor quando o arquivo PCH é criado, as compilações subsequentes que usam o arquivo PCH e/Z7 disparam um aviso. As informações de depuração são colocadas no arquivo. obj atual e símbolos locais definidos no arquivo PCH não estão disponíveis para o depurador.

### <a name="include-path-consistency"></a>Incluir caminho de consistência

Um arquivo PCH não contém informações sobre o caminho de inclusão estava em vigor quando ele foi criado. Quando você usa um arquivo PCH, o compilador sempre usa o caminho de inclusão especificado na compilação atual.

### <a name="source-file-consistency"></a>Consistência do arquivo de origem

Quando você especifica a opção de arquivo de cabeçalho pré-compilado usar (/Yu), o compilador ignora todas as diretivas de pré-processador (incluindo pragmas) que aparecem no código-fonte que será ser pré-compiladas. A compilação especificada por essas diretivas de pré-processador deve ser o mesmo que a compilação usada para a opção de criar a arquivo de cabeçalho pré-compilado (/Yc).

### <a name="pragma-consistency"></a>Consistência de pragma

Pragmas processados durante a criação de um arquivo PCH geralmente afetam o arquivo com o qual o arquivo PCH é usado subsequentemente. O `comment` e `message` pragmas não afetam o restante da compilação.

Esses pragmas afetam somente o código dentro do arquivo PCH; elas não afetam o código que usa, subsequentemente, o arquivo PCH:

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

## <a name="consistency-rules-for-yc-and-yu"></a>Regras de consistência para /Yc e /Yu

Quando você usa um cabeçalho pré-compilado criado usando /Yc ou /Yu, o compilador compara o ambiente de compilação atual para aquela que existia quando você criou o arquivo PCH. Certifique-se de especificar um ambiente consistente com o anterior (usando as opções do compilador consistente, pragmas e assim por diante) para a compilação atual. Se o compilador detecta uma inconsistência, ele emite um aviso e identifica a inconsistência, sempre que possível. Esses avisos não indica necessariamente um problema com o arquivo PCH; eles simplesmente avisá-lo sobre possíveis conflitos. As seções a seguir explicam os requisitos de consistência para cabeçalhos pré-compilados.

### <a name="compiler-option-consistency"></a>Consistência de opção de compilador

Esta tabela lista as opções do compilador que podem disparar um aviso de inconsistência ao usar um cabeçalho pré-compilado:

|Opção|Nome|Regra|
|------------|----------|----------|
|/D|Definir constantes e macros|Deve ser o mesmo entre a compilação que criou o cabeçalho pré-compilado e a compilação atual. O estado das constantes definidas não é verificado, mas poderão ocorrer resultados imprevisíveis se seus arquivos dependem dos valores das constantes alterados.|
|/E ou /EP|Copiar saída de pré-processador para a saída padrão|Cabeçalhos pré-compilados não funcionam com a opção /E ou /EP.|
|/FR ou /FR|Gerar informações de navegador de fonte da Microsoft|Para as opções /Fr e /FR válido com a opção /Yu, eles devem também foram em vigor quando o cabeçalho pré-compilado foi criado. As compilações subsequentes que usam o cabeçalho pré-compilado também geram informações do navegador de origem. Informações sobre o navegador é colocado em um arquivo. SBR único e é referenciado por outros arquivos da mesma maneira como as informações do CodeView. Você não pode substituir o posicionamento de informações do navegador de origem.|
|/ GA, /GD, /GE, /Gw ou /GW|Opções de protocolo do Windows|Deve ser o mesmo entre a compilação que criou o cabeçalho pré-compilado e a compilação atual. Se essas opções forem diferentes, uma mensagem de aviso de resultados.|
|/Zi|Gerar informações de depuração completas|Se essa opção está em vigor quando o cabeçalho pré-compilado é criado, as compilações subsequentes que usam a pré-compilação podem usar essas informações de depuração. Se /Zi não estiver em vigor quando o cabeçalho pré-compilado é criado, as compilações subsequentes que usam a pré-compilação e da opção /Zi ao disparam um aviso. As informações de depuração são colocadas no arquivo de objeto atual e símbolos locais definidos no cabeçalho pré-compilado não estão disponíveis para o depurador.|

> [!NOTE]
>  O recurso de cabeçalho pré-compilado destina-se apenas para uso em arquivos de código-fonte C e C++.

## <a name="using-precompiled-headers-in-a-project"></a>Usando cabeçalhos pré-compilados em um projeto

As seções anteriores apresentam uma visão geral dos cabeçalhos pré-compilados: /Yc e /Yu, a opção /Fp e o [hdrstop](../preprocessor/hdrstop.md) pragma. Esta seção descreve um método para usar as opções de cabeçalho pré-compilado manuais em um projeto; ele termina com um makefile de exemplo e o código que ele gerencia.

Para outra abordagem para usar as opções de cabeçalho pré-compilado manuais em um projeto, estude uma das makefiles localizados no diretório MFC\SRC que é criado durante a configuração padrão do Visual C++. Esses makefiles adotar uma abordagem semelhante ao apresentado nesta seção, mas usar mais de macros do Microsoft programa manutenção Utility (NMAKE) e oferecem maior controle do processo de compilação.

## <a name="pch-files-in-the-build-process"></a>Arquivos PCH no processo de compilação

A base de código de um projeto de software geralmente está contida em vários C ou C++ arquivos de origem, arquivos de objeto, bibliotecas e arquivos de cabeçalho. Normalmente, um makefile coordena a combinação desses elementos em um arquivo executável. A figura a seguir mostra a estrutura de um makefile que usa um arquivo de cabeçalho pré-compilado. Os nomes de macro NMAKE e os nomes de arquivo nesse diagrama são consistentes com aqueles no código de exemplo encontrado na [Makefile de exemplo para PCH](#sample-makefile-for-pch) e [código de exemplo para PCH](#example-code-for-pch).

A figura usa três dispositivos diagramáticas para mostrar o fluxo do processo de compilação. Chamado retângulos representam cada arquivo ou uma macro; as três macros representam um ou mais arquivos. Áreas sombreadas representam cada ação de compilação ou de vinculação. As setas mostram quais arquivos e macros são combinadas durante o processo de vinculação ou compilação.

![Estrutura de um makefile que usa um arquivo de cabeçalho pré-compilado](media/vc30ow1.gif "estrutura de um makefile que usa um arquivo de cabeçalho pré-compilado") <br/>
Estrutura de um Makefile que usa um arquivo de cabeçalho pré-compilado

Começando na parte superior do diagrama, STABLEHDRS e limite são macros NMAKE no qual você provavelmente não precisam de recompilação de arquivos de lista. Esses arquivos são compilados pela cadeia de caracteres de comando

`CL /c /W3 /Yc$(BOUNDRY) applib.cpp myapp.cpp`

somente se o arquivo de cabeçalho pré-compilado (STABLE.pch) não existe ou se você fizer alterações para os arquivos listados em duas macros. Em ambos os casos, o arquivo de cabeçalho pré-compilado conterá código apenas de arquivos listados na macro STABLEHDRS. Lista o último arquivo a que ser pré-compilados na macro limite.

Os arquivos que você listar nessas macros podem ser arquivos de cabeçalho ou arquivos de origem C ou C++. (Um único arquivo PCH não pode ser usado com módulos de C e C++.) Observe que você pode usar o **hdrstop** macro pare de pré-compilação em algum momento dentro do arquivo de limite. Ver [hdrstop](../preprocessor/hdrstop.md) para obter mais informações.

Continuando para baixo no diagrama, APPLIB.obj representa o código de suporte usado em seu aplicativo final. Ele é criado de APPLIB.cpp, os arquivos listados na macro UNSTABLEHDRS e pré-compilados código de cabeçalho pré-compilado.

MYAPP.obj representa o aplicativo final. Ele é criado de MYAPP.cpp, os arquivos listados na macro UNSTABLEHDRS e pré-compilados código de cabeçalho pré-compilado.

Por fim, o arquivo executável (MYAPP. EXE) é criado, vinculando os arquivos listados na macro objetos (APPLIB.obj e MYAPP.obj).

## <a name="sample-makefile-for-pch"></a>Makefile de exemplo para PCH

O makefile a seguir usa as macros e um! SE! ELSE! Estrutura de comando de fluxo de controle ENDIF para simplificar sua adaptação ao seu projeto.

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

Além das macros STABLEHDRS, limite e UNSTABLEHDRS mostradas na figura a "Estrutura de um Makefile que usa um arquivo de cabeçalho pré-compilado" na [arquivos de PCH no processo de compilação](#pch-files-in-the-build-process), este makefile fornece uma macro CLFLAGS e um LINKFLAGS macro. Você deve usar essas macros para listar o compilador e as opções do vinculador que se aplicam se você cria uma depuração ou a versão final do arquivo executável do aplicativo. Há também uma macro de BIBLIOTECAS onde você lista as bibliotecas de seu projeto requer.

Também usa o makefile! SE! ELSE! ENDIF para detectar se você define um símbolo de depuração na linha de comando NMAKE:

```NMAKE
NMAKE DEBUG=[1|0]
```

Esse recurso torna possível para você usar o makefile mesmo durante o desenvolvimento e para as versões finais do seu programa — use DEBUG = 0 para as versões finais. As linhas de comando a seguir são equivalentes:

```NMAKE
NMAKE
NMAKE DEBUG=0
```

Para obter mais informações sobre makefiles, consulte [referência de NMAKE](reference/nmake-reference.md). Consulte também [opções do compilador MSVC](reference/compiler-options.md) e o [opções de vinculador MSVC](reference/linker-options.md).

## <a name="example-code-for-pch"></a>Código de exemplo para PCH

Os seguintes arquivos de origem são usados no makefile descrito em [arquivos de PCH no processo de compilação](#pch-files-in-the-build-process) e [Makefile de exemplo para PCH](#sample-makefile-for-pch). Observe que os comentários contêm informações importantes.

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

[Referência de build C/C++](reference/c-cpp-building-reference.md)<br/>
[Opções do compilador MSVC](reference/compiler-options.md)
