---
title: "Variáveis de ambiente CL | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- cl
dev_langs:
- C++
helpviewer_keywords:
- INCLUDE environment variable
- cl.exe compiler, environment variables
- LIBPATH environment variable
- environment variables, CL compiler
ms.assetid: 2606585b-a681-42ee-986e-1c9a2da32108
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: ba01a980aa24a3ff695479edd08e88d9ea538dcc
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="cl-environment-variables"></a>Variáveis de ambiente CL

A ferramenta de CL usa as seguintes variáveis de ambiente:

- CL e \_CL\_, se definido. A ferramenta de CL precede as opções e argumentos definidos na variável de ambiente CL para os argumentos de linha de comando e acrescenta as opções e argumentos definidos no \_CL\_, antes do processamento.

- INCLUA, que deve apontar para o subdiretório \include da instalação do Visual C++.

- LIBPATH, que especifica os diretórios para procurar por arquivos de metadados referenciados com [#using](../../preprocessor/hash-using-directive-cpp.md). Consulte `#using` para obter mais informações sobre LIBPATH.

Você pode definir o CL ou \_CL\_ variável de ambiente usando a seguinte sintaxe:

> Definir CL = [[*opção*]... [*arquivo*]...] [/ link *link-opt* ...]  
> DEFINIR \_CL\_= [[*opção*]... [*arquivo*]...] [/ link *link-opt* ...]

Para obter detalhes sobre os argumentos de CL e \_CL\_ variáveis de ambiente, consulte [sintaxe de linha de comando do compilador](../../build/reference/compiler-command-line-syntax.md).

Você pode usar essas variáveis de ambiente para definir as opções usadas com mais frequência e arquivos e usar a linha de comando para definir opções e arquivos específicos para fins específicos. O CL e \_CL\_ variáveis de ambiente são limitadas a 1024 caracteres (o limite de entrada de linha de comando).

Você não pode usar a opção /D para definir um símbolo que usa um sinal de igual (=). Você pode substituir o sinal de número (#) para um sinal de igual. Dessa forma, você pode usar o CL ou \_CL\_ variáveis de ambiente para definir constantes pré-processador com valores explícitos — por exemplo, `/DDEBUG#1` para definir `DEBUG=1`.

Para obter informações relacionadas, consulte [definir variáveis de ambiente](../../build/setting-the-path-and-environment-variables-for-command-line-builds.md).

## <a name="examples"></a>Exemplos

Este é um exemplo de configuração de variável de ambiente CL:

> Defina CL = / Zp2 /Ox /I\INCLUDE\MYINCLS \LIB\BINMODE. OBJ

Quando essa variável de ambiente é definida, se você digitar `CL INPUT.C` na linha de comando, este é o comando efetivo:

> CL /Zp2 /Ox /I\INCLUDE\MYINCLS \LIB\BINMODE. ENTRADA DE OBJ. C

O exemplo a seguir faz com que um comando CL simples compilar os arquivos de origem FILE1.c e FILE2.c e, em seguida, vincular os arquivos de objeto FILE1.obj, FILE2.obj e FILE3.obj:

> SET CL = FILE1. FILE2 C. C  
> DEFINIR \_CL\_= ARQUIVO3. OBJ  
> CL  

Isso tem o mesmo efeito que a linha de comando a seguir:

> CL FILE1. FILE2 C. ARQUIVO3 C. OBJ

## <a name="see-also"></a>Consulte também

[Definindo opções do compilador](../../build/reference/setting-compiler-options.md)   
[Opções do Compilador](../../build/reference/compiler-options.md)
