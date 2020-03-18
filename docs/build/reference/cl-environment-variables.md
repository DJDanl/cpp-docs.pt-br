---
title: Variáveis de ambiente CL
ms.date: 06/06/2019
helpviewer_keywords:
- INCLUDE environment variable
- cl.exe compiler, environment variables
- LIBPATH environment variable
- environment variables, CL compiler
ms.assetid: 2606585b-a681-42ee-986e-1c9a2da32108
ms.openlocfilehash: 4d6b1982b1e544459a025d6cb7bee75666e7130e
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79440251"
---
# <a name="cl-environment-variables"></a>Variáveis de ambiente CL

A ferramenta CL usa as seguintes variáveis de ambiente:

- CL e \_CL_, se definido. A ferramenta CL precede as opções e os argumentos definidos na variável de ambiente CL para os argumentos de linha de comando e acrescenta as opções e os argumentos definidos no \_CL_, antes do processamento.

- INCLUIR, que deve apontar para o subdiretório \include da sua instalação do Visual Studio.

- LIBPATH, que especifica os diretórios para pesquisar arquivos de metadados referenciados com [#using](../../preprocessor/hash-using-directive-cpp.md). Para obter mais informações sobre o LIBPATH, consulte [#using](../../preprocessor/hash-using-directive-cpp.md).

Você pode definir a variável de ambiente de CL_ CL ou \_usando a seguinte sintaxe:

> DEFINIR CL = [[*opção*]... [*arquivo*]...] [/link *link-opt* ...] \
> DEFINIR \_CL\_= [[*opção*]... [*arquivo*]...] [/link *link-opt* ...]

Para obter detalhes sobre os argumentos para as variáveis de ambiente CL e \_CL_, consulte [sintaxe de linha de comando do compilador MSVC](compiler-command-line-syntax.md).

Você pode usar essas variáveis de ambiente para definir os arquivos e as opções que você usa com mais frequência. Em seguida, use a linha de comando para fornecer mais arquivos e opções para CL para fins específicos. As variáveis de ambiente de CL_ CL e \_são limitadas a 1024 caracteres (o limite de entrada da linha de comando).

Você não pode usar a opção [/d](d-preprocessor-definitions.md) para definir um símbolo que usa um sinal de igual ( **=** ). Em vez disso, você pode usar o sinal numérico ( **#** ) para um sinal de igual. Dessa forma, você pode usar as variáveis de ambiente CL ou \_CL_ para definir constantes de pré-processador com valores explícitos — por exemplo, `/DDEBUG#1` para definir `DEBUG=1`.

Para obter informações relacionadas, consulte [definir variáveis de ambiente](../setting-the-path-and-environment-variables-for-command-line-builds.md).

## <a name="examples"></a>Exemplos

O comando a seguir é um exemplo de configuração da variável de ambiente CL:

> SET CL =/Zp2/Ox/I\INCLUDE\MYINCLS \LIB\BINMODE. OBJ

Quando a variável de ambiente CL for definida, se você inserir `CL INPUT.C` na linha de comando, o comando efetivo se tornará:

> CL /Zp2 /Ox /I\INCLUDE\MYINCLS \LIB\BINMODE.OBJ INPUT.C

O exemplo a seguir faz com que um comando CL simples compile os arquivos de origem ARQUIVO1. c e FILE2. c e vincule os arquivos de objeto ARQUIVO1. obj, FILE2. obj e ARQUIVO3. obj:

> DEFINA CL = ARQUIVO1. C ARQUIVO2. &
> Defina \_CL_ = ARQUIVO3. OBJ
> CL

Essas variáveis de ambiente fazem a chamada para CL têm o mesmo efeito que a seguinte linha de comando:

> CL ARQUIVO1. C ARQUIVO2. ARQUIVO3 C. OBJ

## <a name="see-also"></a>Consulte também

[Definindo opções de compilador](compiler-command-line-syntax.md) \
[Opções do compilador MSVC](compiler-options.md)
