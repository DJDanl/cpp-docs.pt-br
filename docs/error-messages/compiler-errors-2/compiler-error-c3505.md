---
title: Erro do compilador C3505
ms.date: 11/04/2016
f1_keywords:
- C3505
helpviewer_keywords:
- C3505
ms.assetid: ed73c99e-93a1-4f3a-bac7-ba7ed5d836e4
ms.openlocfilehash: 0c67eb46208c35c1b11a74898107ad3c0e6e570d
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80200837"
---
# <a name="compiler-error-c3505"></a>Erro do compilador C3505

> Não é possível carregar a biblioteca de tipos '*GUID*'

C3505 pode ser causado se você estiver executando o compilador cruzado de 32 bits, hospedado em x86 para destinos de 64 bits, x64 em um computador de 64 bits, porque o compilador está sendo executado sob o WOW64 e só pode ler a partir do hive do registro de 32 bits.

Você pode resolver esse erro criando as versões de 32 bits e de 64 bits da biblioteca de tipos que está tentando importar e, em seguida, registrá-las.  Ou você pode usar o compilador de 64 bits nativo, que exige que você altere a propriedade de **diretórios vc + +** no IDE para apontar para o compilador de 64 bits.

Para obter mais informações, consulte

- [Como habilitar um conjunto de ferramentas Visual C++ de 64 bits na linha de comando](../../build/how-to-enable-a-64-bit-visual-cpp-toolset-on-the-command-line.md)

- [Como configurar projetos do Visual C++ para terem plataformas x64 de 64 bits como destino](../../build/how-to-configure-visual-cpp-projects-to-target-64-bit-platforms.md)
