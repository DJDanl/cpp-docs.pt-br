---
title: Instanciação explícita | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- templates, instantiation
- explicit instantiation
- instantiation, explicit
ms.assetid: 8b0d4e32-45a6-49d5-8041-1ebdd674410e
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 834a71f5fd670874fd7dad5a77cb89a837119c2d
ms.sourcegitcommit: 1fd1eb11f65f2999dfd93a2d924390ed0a0901ed
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/10/2018
ms.locfileid: "37940609"
---
# <a name="explicit-instantiation"></a>Instanciação explícita
Você pode usar uma criação de instanciação explícita para criar uma instanciação de uma classe ou função com modelo sem realmente usá-la no código. Como isso é útil quando você está criando arquivos de biblioteca (.lib) que usam modelos de distribuição, definições de modelo sem instanciação não são colocadas em arquivos de objeto (.obj).  
  
 Esse código cria explicitamente instanciações `MyStack` para **int** variáveis e seis itens:  
  
```cpp  
template class MyStack<int, 6>;  
```  
  
 Essa instrução cria uma instanciação de `MyStack` sem reservar nenhum armazenamento para um objeto. O código é gerado para todos os membros.  
  
 A linha a seguir cria instanciações explicitamente somente para a função membro do construtor:  
  
```cpp  
template MyStack<int, 6>::MyStack( void );  
```  
  
 Você pode instanciar explicitamente os modelos de função usando um argumento de tipo específico para declará-los, novamente, conforme mostrado no exemplo na [instanciação do modelo de função](../cpp/function-template-instantiation.md).  
  
 Você pode usar o **extern** palavra-chave para evitar a criação automática de instanciações de membros. Por exemplo:  
  
```cpp  
extern template class MyStack<int, 6>;  
```  
  
 De forma semelhante, você pode marcar membros específicos como sendo externos e sem instanciação:  
  
```cpp  
extern template MyStack<int, 6>::MyStack( void );  
```  
  
 Você pode usar o **extern** palavra-chave para impedir que o compilador gerar o mesmo código de instanciação em mais de um módulo de objeto. Você deve instanciar a função do modelo usando os parâmetros de modelo explícitos especificados em pelo menos um módulo vinculado, caso a função seja chamada, ou receberá um erro do vinculador quando o programa for criado.  
  
> [!NOTE]
>  O **extern** palavra-chave na especialização se aplica somente a funções de membro definidas fora do corpo da classe. As funções definidas na declaração de classe são consideradas funções embutidas e sempre têm instanciações.  
  
## <a name="see-also"></a>Consulte também  
 [Modelos de função](../cpp/function-templates.md)