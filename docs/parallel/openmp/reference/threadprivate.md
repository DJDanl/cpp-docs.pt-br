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
ms.openlocfilehash: e7e7edaa36f929750087e3c81f42204ff20e9f62
ms.sourcegitcommit: 7019081488f68abdd5b2935a3b36e2a5e8c571f8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
---
# <a name="threadprivate"></a>threadprivate
Especifica que uma variável privada para um thread.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
#pragma omp threadprivate(var)  
```  
  
## <a name="remarks"></a>Comentários  
 onde,  
  
 `var`  
 Uma lista separada por vírgulas de variáveis que você deseja tornar privado a um thread. `var` deve ser uma variável global - ou escopo de namespace ou uma variável estática local.  
  
## <a name="remarks"></a>Comentários  
 O `threadprivate` diretiva dá suporte a nenhuma cláusulas OpenMP.  
  
 Para obter mais informações, consulte [2.7.1 diretiva threadprivate](../../../parallel/openmp/2-7-1-threadprivate-directive.md).  
  
 O `threadprivate` diretiva se baseia o [thread](../../../cpp/thread.md) `__declspec` atributo; limites **__declspec(thread)** se aplicam a `threadprivate`.  
  
 Não é possível usar `threadprivate` em qualquer DLL que será carregado por meio de [LoadLibrary](http://msdn.microsoft.com/library/windows/desktop/ms684175).  Isso inclui DLLs carregadas com [/DELAYLOAD (importação de carga com atraso)](../../../build/reference/delayload-delay-load-import.md), que também usa **LoadLibrary**.  
  
 Você pode usar `threadprivate` em uma DLL que é carregada estaticamente na inicialização do processo.  
  
 Porque `threadprivate` baseia-se em **__declspec(thread)**, um `threadprivate` variável existirá em qualquer thread iniciado no processo, não apenas os threads que fazem parte de uma equipe de thread gerada por uma região parallel.  Este é um detalhe de implementação que talvez você queira conhecer, desde que você pode perceber, por exemplo, construtores para uma `threadprivate` tipo definido pelo usuário chamado mais frequentemente e esperado.  
  
 Um `threadprivate` não é garantia de variável de um tipo destructable ter seu destruidor chamado.  Por exemplo:  
  
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
  
 Os usuários não têm controle sobre quando os threads que constitui a região paralela serão encerrado.  Se esses threads existirem quando o processo foi encerrado, os threads não serão notificados sobre a saída do processo e o destruidor não será chamado para `threaded_var` em qualquer thread, exceto o que sai (aqui, o thread principal).  Para código não deve contar com a destruição adequada de `threadprivate` variáveis.  
  
## <a name="example"></a>Exemplo  
 Para obter um exemplo do uso de `threadprivate`, consulte [particular](../../../parallel/openmp/reference/private-openmp.md).  
  
## <a name="see-also"></a>Consulte também  
 [Diretivas](../../../parallel/openmp/reference/openmp-directives.md)