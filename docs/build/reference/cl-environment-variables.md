---
title: Variáveis de ambiente CL
ms.date: 06/06/2019
f1_keywords:
- cl
helpviewer_keywords:
- INCLUDE environment variable
- cl.exe compiler, environment variables
- LIBPATH environment variable
- environment variables, CL compiler
ms.assetid: 2606585b-a681-42ee-986e-1c9a2da32108
ms.openlocfilehash: 0f7930728ef1bf6bea50c4388d52d30c569a8795
ms.sourcegitcommit: 8adabe177d557c74566c13145196c11cef5d10d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/10/2019
ms.locfileid: "66821525"
---
# <a name="cl-environment-variables"></a>Variáveis de ambiente CL

A ferramenta de CL usa as seguintes variáveis de ambiente:

- CL e \_CL_, se definido. A ferramenta de CL precede as opções e argumentos definidos na variável de ambiente CL aos argumentos de linha de comando e acrescenta as opções e argumentos definidos em \_CL_ antes do processamento.

- INCLUA, que deve apontar para o subdiretório \include. da instalação do Visual Studio.

- LIBPATH, que especifica os diretórios para pesquisar arquivos de metadados referenciados com [#using](../../preprocessor/hash-using-directive-cpp.md). Para obter mais informações sobre LIBPATH, consulte [#using](../../preprocessor/hash-using-directive-cpp.md).

Você pode definir o CL ou \_variável de ambiente CL_ usando a seguinte sintaxe:

> Definir CL = [[*opção*]... [*arquivo*]...] [/link *link-opt* ...] \
> DEFINIR \_CL\_= [[*opção*]... [*arquivo*]...] [/link *link-opt* ...]

Para obter detalhes sobre os argumentos para o CL e \_CL_ variáveis de ambiente, consulte [sintaxe de linha de comando do compilador MSVC](compiler-command-line-syntax.md).

Você pode usar essas variáveis de ambiente para definir os arquivos e as opções que você pode usar com mais frequência. Em seguida, use a linha de comando para dar mais arquivos e opções ao CL para finalidades específicas. O CL e \_variáveis de ambiente CL_ são limitadas a 1024 caracteres (o limite de entrada de linha de comando).

Não é possível usar o [/D](d-preprocessor-definitions.md) opção de definir um símbolo que usa um sinal de igual ( **=** ). Em vez disso, você pode usar o sinal de número ( **#** ) para um sinal de igual. Dessa forma, você pode usar o CL ou \_variáveis de ambiente CL_ para definir constantes de pré-processador com valores explícitos — por exemplo, `/DDEBUG#1` para definir `DEBUG=1`.

Para obter informações relacionadas, consulte [definir variáveis de ambiente](../setting-the-path-and-environment-variables-for-command-line-builds.md).

## <a name="examples"></a>Exemplos

O comando a seguir está um exemplo de como definir a variável de ambiente CL:

> SET CL=/Zp2 /Ox /I\INCLUDE\MYINCLS \LIB\BINMODE.OBJ

Quando a variável de ambiente CL é definida, se você inserir `CL INPUT.C` na linha de comando, o comando efetivo torna-se:

> CL /Zp2 /Ox /I\INCLUDE\MYINCLS \LIB\BINMODE.OBJ INPUT.C

O exemplo a seguir faz com que um simples comando CL compilar os arquivos de origem FILE1.c e FILE2.c e, em seguida, vincule os arquivos de objeto FILE1.obj, FILE2.obj e FILE3.obj:

> CONJUNTO DE CL = FILE1. ARQUIVO2 C. C \
> SET \_CL_=FILE3.OBJ \
> CL

Essas variáveis de ambiente fazer a chamada para CL têm o mesmo efeito que a linha de comando a seguir:

> CL FILE1.C FILE2.C FILE3.OBJ

## <a name="see-also"></a>Consulte também

[Definindo opções do compilador](compiler-command-line-syntax.md) \
[Opções do compilador MSVC](compiler-options.md)
