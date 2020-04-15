---
title: Arquivos de cabeçalho pré-compilado
ms.date: 10/24/2019
helpviewer_keywords:
- precompiled header files, creating
- PCH files, creating
- cl.exe compiler, precompiling code
- .pch files, creating
ms.assetid: e2cdb404-a517-4189-9771-c869c660cb1b
ms.openlocfilehash: 158301ec3caacced1663892071b17ef2b8f8e741
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81328665"
---
# <a name="precompiled-header-files"></a>Arquivos de cabeçalho pré-compilado

Quando você cria um novo projeto no Visual Studio, um *arquivo de cabeçalho pré-compilado* chamado *pch.h* é adicionado ao projeto. (No Visual Studio 2017 e anteriormente, o arquivo foi chamado *de stdafx.h*.) O objetivo do arquivo é acelerar o processo de construção. Quaisquer arquivos de cabeçalho estáveis, `<vector>`por exemplo, cabeçalhos da Biblioteca Padrão, como , devem ser incluídos aqui. O cabeçalho pré-compilado é compilado somente quando ele, ou quaisquer arquivos que ele inclui, são modificados. Se você fizer apenas alterações no código-fonte do projeto, a compilação pulará a compilação para o cabeçalho pré-compilado.

As opções de compilador para cabeçalhos pré-compilados são [/Y](reference/y-precompiled-headers.md). Nas páginas de propriedade do projeto, as opções estão localizadas em **Propriedades de configuração > C/C++ > Cabeçalhos pré-compilados**. Você pode optar por não usar cabeçalhos pré-compilados e pode especificar o nome do arquivo de cabeçalho e o nome e o caminho do arquivo de saída.

## <a name="custom-precompiled-code"></a>Código pré-compilado personalizado

Para grandes projetos que levam tempo significativo para serem construídos, você pode querer considerar a criação de arquivos pré-compilados personalizados. Os compiladores C e C++ da Microsoft fornecem opções para pré-compilar qualquer código C ou C++, incluindo código embutido. Usando esse recurso de desempenho, é possível compilar um corpo de código estável, armazenar o estado compilado do código em um arquivo e, durante as compilações subsequentes, combinar o código pré-compilado com código que ainda está em desenvolvimento. Cada compilação subsequente é mais rápida, porque o código estável não precisa ser recompilado.

## <a name="when-to-precompile-source-code"></a>Quando pré-compilar o código-fonte

O código pré-compilado é útil durante o ciclo de desenvolvimento para reduzir o tempo de compilação, especialmente se:

- Você sempre usa um grande corpo de código que muda com pouca freqüência.

- Seu programa compreende vários módulos, todos os quais usam um conjunto padrão de arquivos de inclusão e as mesmas opções de compilação. Neste caso, todos os arquivos incluem pode ser pré-compilado em um cabeçalho pré-compilado.

A primeira compilação — aquela que cria o arquivo de cabeçalho pré-compilado (PCH) — leva um pouco mais do que as compilações subseqüentes. Compilações subseqüentes podem prosseguir mais rapidamente, incluindo o código pré-compilado.

Você pode pré-compilar os programas C e C++. Na programação C++, é prática comum separar informações de interface de classe em arquivos de cabeçalho. Esses arquivos de cabeçalho podem ser incluídos posteriormente em programas que usam a classe. Ao pré-compilar esses cabeçalhos, você pode reduzir o tempo que um programa leva para compilar.

> [!NOTE]
> Embora você possa usar apenas um arquivo de cabeçalho pré-compilado (.pch) por arquivo de origem, você pode usar vários arquivos .pch em um projeto.

## <a name="two-choices-for-precompiling-code"></a>Duas escolhas para pré-compilar código

Você pode pré-compilar qualquer código C ou C++; você não está limitado a precompilar apenas arquivos de cabeçalho.

A pré-compilação requer planejamento, mas oferece compilações significativamente mais rápidas se você pré-compilar código-fonte que não seja arquivos de cabeçalho simples.

Pré-compilar código quando você sabe que seus arquivos de origem usam conjuntos comuns de arquivos de cabeçalho, mas não os inclui na mesma ordem ou quando você deseja incluir código fonte em sua pré-compilação.

As opções de cabeçalho pré-compilado são [/Yc (Criar arquivo de cabeçalho pré-compilado)](reference/yc-create-precompiled-header-file.md) e [/Yu (Use Arquivo de cabeçalho pré-compilado)](reference/yu-use-precompiled-header-file.md). Use **/Yc** para criar um cabeçalho pré-compilado. Quando usado com o pragma [hdrstop](../preprocessor/hdrstop.md) opcional, **/Yc** permite que você precompile arquivos de cabeçalho e código-fonte. Selecione **/Yu** para usar um cabeçalho pré-compilado existente na compilação existente. Você também pode usar **/Fp** com as opções **/Yc** e **/Yu** para fornecer um nome alternativo para o cabeçalho pré-compilado.

Os tópicos de referência da opção compilador para **/Yu** e **/Yc** discutem como acessar essa funcionalidade no ambiente de desenvolvimento.

## <a name="precompiled-header-consistency-rules"></a>Regras de consistência do cabeçalho pré-compilado

Como os arquivos PCH contêm informações sobre o ambiente da máquina, bem como informações de endereço de memória sobre o programa, você só deve usar um arquivo PCH na máquina onde ele foi criado.

## <a name="consistency-rules-for-per-file-use-of-precompiled-headers"></a>Regras de consistência para uso por arquivo de cabeçalhos pré-compilados

A opção [compilador /Yu](reference/yu-use-precompiled-header-file.md) permite especificar qual arquivo PCH usar.

Quando você usa um arquivo PCH, o compilador assume o mesmo ambiente de compilação — aquele que usa opções consistentes de compilador, pragmas e assim por diante — que estava em vigor quando você criou o arquivo PCH, a menos que você especifique o contrário. Se o compilador detectar uma inconsistência, ele emite um aviso e identifica a inconsistência sempre que possível. Tais avisos não indicam necessariamente um problema com o arquivo PCH; eles simplesmente avisam sobre possíveis conflitos. Os requisitos de consistência para arquivos PCH são descritos nas seções a seguir.

### <a name="compiler-option-consistency"></a>Consistência da opção do compilador

As seguintes opções de compilador podem ativar um aviso de inconsistência ao usar um arquivo PCH:

- As macros criadas usando a opção Pré-processador (/D) devem ser as mesmas entre a compilação que criou o arquivo PCH e a compilação atual. O estado das constantes definidas não é verificado, mas resultados imprevisíveis podem ocorrer se essas mudanças.

- Os arquivos PCH não funcionam com as opções /E e /EP.

- Os arquivos PCH devem ser criados usando a opção Gerar informações de navegação (/FR) ou a opção Excluir variáveis locais (/Fr) antes que compilações subseqüentes que usam o arquivo PCH possam usar essas opções.

### <a name="c-70-compatible-z7"></a>C 7.0 compatível (/Z7)

Se essa opção estiver em vigor quando o arquivo PCH for criado, compilações subseqüentes que usam o arquivo PCH podem usar as informações de depuração.

Se a opção C 7.0-Compatible (/Z7) não estiver em vigor quando o arquivo PCH for criado, compilações subseqüentes que usam o arquivo PCH e /Z7 disparam um aviso. As informações de depuração são colocadas no arquivo atual .obj, e os símbolos locais definidos no arquivo PCH não estão disponíveis para o depurador.

### <a name="include-path-consistency"></a>Incluir consistência do caminho

Um arquivo PCH não contém informações sobre o caminho de inclusão que estava em vigor quando foi criado. Quando você usa um arquivo PCH, o compilador sempre usa o caminho de inclusão especificado na compilação atual.

### <a name="source-file-consistency"></a>Consistência do arquivo de origem

Quando você especifica a opção Usar arquivo de cabeçalho pré-compilado (/Yu), o compilador ignora todas as diretivas de pré-processador (incluindo pragmas) que aparecem no código-fonte que será pré-compilado. A compilação especificada por tais diretivas de pré-processador deve ser a mesma da compilação usada para a opção Criar arquivo de cabeçalho pré-compilado (/Yc).

### <a name="pragma-consistency"></a>Consistência de Pragma

Pragmas processados durante a criação de um arquivo PCH geralmente afetam o arquivo com o qual o arquivo PCH é posteriormente usado. Os `comment` `message` pragmas e os pragmas não afetam o restante da compilação.

Esses pragmas afetam apenas o código dentro do arquivo PCH; eles não afetam o código que posteriormente usa o arquivo PCH:

||||
|-|-|-|
|`comment`|`page`|`subtitle`|
|`linesize`|`pagesize`|`title`|
|`message`|`skip`||

Esses pragmas são retidos como parte de um cabeçalho pré-compilado, e afetam o restante de uma compilação que usa o cabeçalho pré-compilado:

||||
|-|-|-|
|`alloc_text`|`include_alias`|`pack`|
|`auto_inline`|`init_seg`|`pointers_to_members`|
|`check_stack`|`inline_depth`|`setlocale`|
|`code_seg`|`inline_recursion`|`vtordisp`|
|`data_seg`|`intrinsic`|`warning`|
|`function`|`optimize`||

## <a name="consistency-rules-for-yc-and-yu"></a>Regras de consistência para /Yc e /Yu

Quando você usa um cabeçalho pré-compilado criado usando /Yc ou /Yu, o compilador compara o ambiente de compilação atual com o que existia quando você criou o arquivo PCH. Certifique-se de especificar um ambiente consistente com o anterior (usando opções consistentes de compilador, pragmas e assim por diante) para a compilação atual. Se o compilador detectar uma inconsistência, ele emite um aviso e identifica a inconsistência sempre que possível. Tais avisos não indicam necessariamente um problema com o arquivo PCH; eles simplesmente avisam sobre possíveis conflitos. As seções a seguir explicam os requisitos de consistência para cabeçalhos pré-compilados.

### <a name="compiler-option-consistency"></a>Consistência da opção do compilador

Esta tabela lista opções de compilação que podem desencadear um aviso de inconsistência ao usar um cabeçalho pré-compilado:

|Opção|Nome|Regra|
|------------|----------|----------|
|/D|Definir constantes e macros|Deve ser o mesmo entre a compilação que criou o cabeçalho pré-compilado e a compilação atual. O estado das constantes definidas não é verificado, mas resultados imprevisíveis podem ocorrer se seus arquivos dependerem dos valores das constantes alteradas.|
|/E ou /EP|Copiar a saída do pré-processador para a saída padrão|Os cabeçalhos pré-compilados não funcionam com a opção /E ou /EP.|
|/Fr ou /FR|Gerar informações do Navegador de Origem do Microsoft|Para que as opções /Fr e /FR sejam válidas com a opção /Yu, elas também devem ter sido efetivadas quando o cabeçalho pré-compilado foi criado. Compilações subseqüentes que usam o cabeçalho pré-compilado também geram informações do Source Browser. As informações do navegador são colocadas em um único arquivo .sbr e são referenciadas por outros arquivos da mesma forma que as informações do CodeView. Não é possível substituir a colocação de informações do Navegador de Origem.|
|/GA, /GD, /GE, /Gw, ou /GW|Opções de protocolo do Windows|Deve ser o mesmo entre a compilação que criou o cabeçalho pré-compilado e a compilação atual. Se essas opções diferem, uma mensagem de aviso resulta.|
|/Zi|Gerar informações completas de depuração|Se essa opção estiver em vigor quando o cabeçalho pré-compilado for criado, compilações subseqüentes que usam a pré-compilação podem usar essas informações de depuração. Se /Zi não estiver em vigor quando o cabeçalho pré-compilado for criado, compilações subseqüentes que usam a pré-compilação e a opção /Zi disparam um aviso. As informações de depuração são colocadas no arquivo objeto atual e os símbolos locais definidos no cabeçalho pré-compilado não estão disponíveis para o depurador.|

> [!NOTE]
> A instalação de cabeçalho pré-compilada destina-se a ser usada apenas em arquivos de origem C e C++.

## <a name="using-precompiled-headers-in-a-project"></a>Usando cabeçalhos pré-compilados em um projeto

As seções anteriores apresentam uma visão geral dos cabeçalhos pré-compilados: /Yc e /Yu, a opção /Fp e o pragma [hdrstop.](../preprocessor/hdrstop.md) Esta seção descreve um método para usar as opções manuais de cabeçalho pré-compilado em um projeto; ele termina com um exemplo makefile e o código que ele gerencia.

Para outra abordagem para usar as opções manuais de cabeçalho pré-compilado em um projeto, estude um dos makefiles localizados no diretório MFC\SRC que é criado durante a configuração padrão do Visual Studio. Esses arquivos fazem uma abordagem semelhante à apresentada nesta seção, mas fazem maior uso das macros NMAKE (Microsoft Program Maintenance Utility, utilitário de manutenção do programa microsoft) e oferecem maior controle do processo de compilação.

## <a name="pch-files-in-the-build-process"></a>Arquivos PCH no processo de compilação

A base de código de um projeto de software geralmente está contida em vários arquivos de origem C ou C++, arquivos de objetos, bibliotecas e arquivos de cabeçalho. Normalmente, um makefile coordena a combinação desses elementos em um arquivo executável. A figura a seguir mostra a estrutura de um arquivo de makeque usa um arquivo de cabeçalho pré-compilado. Os nomes de macro NMAKE e os nomes dos arquivos neste diagrama são consistentes com aqueles no código de exemplo encontrado no [Sample Makefile for PCH](#sample-makefile-for-pch) e [Example Code for PCH](#example-code-for-pch).

A figura usa três dispositivos diaticalógicos para mostrar o fluxo do processo de compilação. Retângulos nomeados representam cada arquivo ou macro; as três macros representam um ou mais arquivos. As áreas sombreadas representam cada ação de compilação ou link. Setas mostram quais arquivos e macros são combinados durante o processo de compilação ou vinculação.

![Estrutura de um makefile que usa um arquivo de cabeçalho pré-compilado](media/vc30ow1.gif "Estrutura de um makefile que usa um arquivo de cabeçalho pré-compilado") <br/>
Estrutura de um makefile que usa um arquivo de cabeçalho pré-compilado

Começando na parte superior do diagrama, tanto STABLEHDRS quanto BOUNDRY são macros NMAKE nas quais você lista arquivos que não precisam de recompilação. Esses arquivos são compilados pela seqüência de comandos

`CL /c /W3 /Yc$(BOUNDRY) applib.cpp myapp.cpp`

somente se o arquivo de cabeçalho pré-compilado (STABLE.pch) não existir ou se você fizer alterações nos arquivos listados nas duas macros. Em ambos os casos, o arquivo de cabeçalho pré-compilado conterá código apenas dos arquivos listados na macro STABLEHDRS. Liste o último arquivo que deseja pré-compilado na macro BOUNDRY.

Os arquivos que você lista nessas macros podem ser arquivos de cabeçalho ou arquivos de origem C ou C++. (Um único arquivo PCH não pode ser usado com módulos C e C++.) Observe que você pode usar a macro **hdrstop** para parar a pré-compilação em algum momento dentro do arquivo BOUNDRY. Consulte [hdrstop](../preprocessor/hdrstop.md) para obter mais informações.

Continuando o diagrama, APPLIB.obj representa o código de suporte usado em sua aplicação final. Ele é criado a partir de APPLIB.cpp, os arquivos listados na macro UNSTABLEHDRS e código pré-compilado a partir do cabeçalho pré-compilado.

MYAPP.obj representa sua aplicação final. Ele é criado a partir de MYAPP.cpp, os arquivos listados na macro UNSTABLEHDRS e código pré-compilado a partir do cabeçalho pré-compilado.

Finalmente, o arquivo executável (MYAPP. EXE) é criado vinculando os arquivos listados na macro OBJS (APPLIB.obj e MYAPP.obj).

## <a name="sample-makefile-for-pch"></a>Makefile de exemplo para PCH

O makefile a seguir usa macros e um ! Se! Mais! Estrutura de comando de fluxo de controle ENDIF para simplificar sua adaptação ao seu projeto.

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
LINKFLAGS = /nologo
!IF "$(DEBUG)" == "1"
CLFLAGS   = /D_DEBUG $(CLFLAGS) /Od /Zi
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

Além das macros STABLEHDRS, BOUNDRY e UNSTABLEHDRS mostradas na figura "Estrutura de um Makefile que usa um arquivo de cabeçalho pré-compilado" [em arquivos PCH no Processo de compilação,](#pch-files-in-the-build-process)este makefile fornece uma macro CLFLAGS e uma macro LINKFLAGS. Você deve usar essas macros para listar opções de compilador e linker que se aplicam se você constrói uma versão depuração ou final do arquivo executável do aplicativo. Há também uma macro LIBS onde você lista as bibliotecas que seu projeto requer.

O makefile também usa! Se! Mais! ENDIF para detectar se você define um símbolo DEBUG na linha de comando NMAKE:

```NMAKE
NMAKE DEBUG=[1|0]
```

Esse recurso permite que você use o mesmo makefile durante o desenvolvimento e para as versões finais do seu programa — use DEBUG=0 para as versões finais. As seguintes linhas de comando são equivalentes:

```NMAKE
NMAKE
NMAKE DEBUG=0
```

Para obter mais informações sobre makefiles, consulte [NMAKE Reference](reference/nmake-reference.md). Consulte também [as opções do compilador MSVC](reference/compiler-options.md) e as opções de [linker Do MSVC.](reference/linker-options.md)

## <a name="example-code-for-pch"></a>Código de exemplo para PCH

Os seguintes arquivos de origem são usados no makefile descrito em [PCH Files no Build Process](#pch-files-in-the-build-process) e Sample [Makefile for PCH](#sample-makefile-for-pch). Observe que os comentários contêm informações importantes.

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
#include<iostream>
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
using namespace std;
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

## <a name="see-also"></a>Confira também

[Referência de build C/C++](reference/c-cpp-building-reference.md)<br/>
[Opções do compilador MSVC](reference/compiler-options.md)
