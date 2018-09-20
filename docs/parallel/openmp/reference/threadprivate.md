---
title: threadprivate | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: reference
f1_keywords:
- threadprivate
dev_langs:
- C++
helpviewer_keywords:
- threadprivate OpenMP directive
ms.assetid: 3515aaed-6f9d-4d59-85eb-342378bea2d3
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: a9313934744f6eae66736f25b0d0b8592743cf12
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46376974"
---
# <a name="threadprivate"></a>threadprivate

Especifica que uma variável privada em um thread.

## <a name="syntax"></a>Sintaxe

```
#pragma omp threadprivate(var)
```

### <a name="parameters"></a>Parâmetros

*var*<br/>
Uma lista separada por vírgulas de variáveis que você deseja tornar particular a um thread. `var` deve ser uma variável global - ou no escopo de namespace ou uma variável estática de local.

## <a name="remarks"></a>Comentários

O `threadprivate` diretiva dá suporte a nenhuma cláusulas OpenMP.

Para obter mais informações, consulte [2.7.1 diretiva threadprivate](../../../parallel/openmp/2-7-1-threadprivate-directive.md).

O `threadprivate` diretiva se baseia o [thread](../../../cpp/thread.md) `__declspec` atributo; limites **__declspec(thread)** se aplicam a `threadprivate`.

Não é possível usar `threadprivate` em qualquer DLL que será carregado por meio [LoadLibrary](https://msdn.microsoft.com/library/windows/desktop/ms684175).  Isso inclui as DLLs carregadas com [/DELAYLOAD (importação de carga com atraso)](../../../build/reference/delayload-delay-load-import.md), que também usa **LoadLibrary**.

Você pode usar `threadprivate` em uma DLL que estaticamente é carregada na inicialização do processo.

Porque `threadprivate` se baseia **__declspec(thread)**, um `threadprivate` variável continuará a existir em qualquer thread iniciado no processo, não apenas os threads que fazem parte de uma equipe de thread gerada por uma região paralela.  Isso é um detalhe de implementação que você talvez queira conhecer, uma vez que você pode observar, por exemplo, construtores para uma `threadprivate` tipo definido pelo usuário chamada mais frequentemente e esperado.

Um `threadprivate` variável de um tipo destructable não é garantida para ter seu destruidor chamado.  Por exemplo:

```
struct MyType
{
    ~MyType();
};

MyType threaded_var;
#pragma omp threadprivate(threaded_var)
int main()
{
    #pragma omp parallel
    {}
}
```

Os usuários não tem controle sobre quando os threads que constitui a região paralela serão encerrado.  Se esses threads existirem quando o processo for encerrado, os threads não serão notificados sobre a saída do processo e o destruidor não será chamado para `threaded_var` em qualquer thread, exceto o que é encerrado (aqui, o thread primário).  Para que o código não deve contar com a destruição correta de `threadprivate` variáveis.

## <a name="example"></a>Exemplo

Para obter um exemplo de uso `threadprivate`, consulte [privada](../../../parallel/openmp/reference/private-openmp.md).

## <a name="see-also"></a>Consulte também

[Diretivas](../../../parallel/openmp/reference/openmp-directives.md)