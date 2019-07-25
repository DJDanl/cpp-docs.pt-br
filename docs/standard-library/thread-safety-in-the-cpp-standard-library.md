---
title: Segurança de threads na Biblioteca Padrão C++
ms.date: 11/04/2016
helpviewer_keywords:
- thread safety
- C++ Standard Library, thread safety
- thread safety, C++ Standard Library
ms.assetid: 9351c8fb-4539-4728-b0e9-226e2ac4284b
ms.openlocfilehash: 4ac029a119a77fa87c6cd004fece9c4e6b382026
ms.sourcegitcommit: 0dcab746c49f13946b0a7317fc9769130969e76d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/24/2019
ms.locfileid: "68460059"
---
# <a name="thread-safety-in-the-c-standard-library"></a>Segurança de threads na Biblioteca Padrão C++

As regras de acesso thread-safe a seguir se aplicam a todas as classes da Biblioteca Padrão C++. Isso inclui `shared_ptr`, conforme descrito abaixo.  Às vezes, são dadas garantias maiores – por exemplo, os objetos iostream padrão, conforme descrito abaixo e os tipos projetados especificamente para multithreading, como aqueles em [\<atomic>](../standard-library/atomic.md).

Um objeto é thread-safe para leitura de vários threads. Por exemplo, dado um objeto A, é seguro ler A do thread 1 e do thread 2 simultaneamente.

Se um objeto estiver sendo gravado por um thread, todas as leituras e as gravações nesse objeto no mesmo thread ou em outros deverão ser protegidas. Por exemplo, dado um objeto A, se o thread 1 estiver sendo gravado em A, o thread 2 deverá ser impedido de ler de ou gravar em A.

É seguro ler e gravar em uma instância de um tipo, mesmo que outro thread esteja lendo ou gravando em uma instância diferente do mesmo tipo. Por exemplo, dados os objetos A e B do mesmo tipo, é seguro quando A está sendo gravado no thread 1 e B está sendo gravado no thread 2.

## <a name="sharedptr"></a>shared_ptr

Vários threads podem ler e gravar simultaneamente objetos [shared_ptr](../standard-library/shared-ptr-class.md) diferentes, mesmo quando os objetos são cópias que compartilham a propriedade.

## <a name="iostream"></a>iostream

Os objetos iostream padrão `cin`, `cout`, `cerr`, `clog`, `wcin`, `wcout`, `wcerr` e `wclog` seguem as mesmas regras das outras classes, com esta exceção: é seguro gravar em um objeto de vários threads. Por exemplo, o thread 1 pode gravar em [cout](../standard-library/iostream.md#cout) ao mesmo tempo que o thread 2. Porém, isso pode misturar a saída dos dois threads.

> [!NOTE]
> A leitura de um buffer de stream não é considerada uma operação segura. Em vez disso, ela é considerada um operação de gravação, porque o estado da classe muda.

## <a name="see-also"></a>Consulte também

[Visão geral da biblioteca padrão C++](../standard-library/cpp-standard-library-overview.md)
