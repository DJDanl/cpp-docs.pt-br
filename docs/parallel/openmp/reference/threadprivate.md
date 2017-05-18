---
title: threadprivate | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- threadprivate
dev_langs:
- C++
helpviewer_keywords:
- threadprivate OpenMP directive
ms.assetid: 3515aaed-6f9d-4d59-85eb-342378bea2d3
caps.latest.revision: 11
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 2f5d64c172cac629a80cdf4a1057afbbf9789f5f
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

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
 Uma lista separada por vírgulas de variáveis que você deseja tornar particular a um thread. `var`deve ser uma variável global - ou escopo de namespace ou uma variável estática local.  
  
## <a name="remarks"></a>Comentários  
 A `threadprivate` diretiva oferece suporte a nenhum cláusulas OpenMP.  
  
 Para obter mais informações, consulte [2.7.1 diretiva threadprivate](../../../parallel/openmp/2-7-1-threadprivate-directive.md).  
  
 O `threadprivate` diretiva se baseia o [thread](../../../cpp/thread.md) `__declspec` atributo; limites **__declspec(thread)** se aplicam a `threadprivate`.  
  
 Não é possível usar `threadprivate` em qualquer DLL que será carregado por meio de [LoadLibrary](http://msdn.microsoft.com/library/windows/desktop/ms684175).  Isso inclui as DLLs carregadas com [/DELAYLOAD (importação de carga com atraso)](../../../build/reference/delayload-delay-load-import.md), que também usa **LoadLibrary**.  
  
 Você pode usar `threadprivate` em uma DLL que é carregada na inicialização do processo estaticamente.  
  
 Porque `threadprivate` baseia-se em **__declspec(thread)**, um `threadprivate` variável existirá em qualquer thread iniciado no processo, não apenas os threads que fazem parte de uma equipe de thread gerada por uma região paralela.  Isso é um detalhe de implementação que talvez você queira conhecer, como você pode observar, por exemplo, construtores para uma `threadprivate` tipo definido pelo usuário chamado mais frequentemente e esperado.  
  
 Um `threadprivate` variável de tipo destructable não é garantida para ter seu destruidor chamado.  Por exemplo:  
  
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
  
 Os usuários não têm controle sobre quando os threads que constitui a região paralela serão encerrado.  Se desses segmentos existirem quando o processo for encerrado, os threads não serão notificados sobre a saída do processo e o destruidor não será chamado para `threaded_var` em qualquer thread, exceto o que sai (aqui, o thread primário).  Para o código não deve contar com destruição adequada de `threadprivate` variáveis.  
  
## <a name="example"></a>Exemplo  
 Para obter um exemplo de uso `threadprivate`, consulte [particular](../../../parallel/openmp/reference/private-openmp.md).  
  
## <a name="see-also"></a>Consulte também  
 [Diretivas](../../../parallel/openmp/reference/openmp-directives.md)
