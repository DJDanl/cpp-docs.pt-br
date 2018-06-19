---
title: Funções SafeInt | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- functions, SafeInt
ms.assetid: fdc208e5-5d8a-41a9-8271-567fd438958d
author: ghogen
ms.author: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 97edd25abca3c9e80a35745165eedc93cc13a9b9
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33889300"
---
# <a name="safeint-functions"></a>Funções (SafeInt)
A biblioteca de SafeInt fornece várias funções que você pode usar sem criar uma instância do [classe SafeInt](../windows/safeint-class.md). Se você quiser proteger uma única operação matemática de estouro de inteiro, você pode usar essas funções. Se você deseja proteger várias operações matemáticas, você deve criar `SafeInt` objetos. É mais eficiente criar `SafeInt` objetos de usar essas funções várias vezes.  
  
 Estas funções permitem comparar ou executar operações matemáticas em dois tipos diferentes de parâmetros sem precisar primeiro convertê-los para o mesmo tipo.  
  
 Cada uma dessas funções tem dois tipos de modelo: `T` e `U`. Cada um desses tipos pode ser um booliano, caractere ou tipo integral. Tipos integrais podem ser assinados ou não assinados e qualquer tamanho de 8 bits para 64 bits.  
  
## <a name="in-this-section"></a>Nesta seção  
  
|Função|Descrição|  
|--------------|-----------------|  
|[SafeAdd](../windows/safeadd.md)|Adiciona dois números e protege contra estouro.|  
|[SafeCast](../windows/safecast.md)|Converte um tipo de parâmetro para outro tipo.|  
|[SafeDivide](../windows/safedivide.md)|Divide dois números e protege contra a divisão por zero.|  
|[SafeEquals](../windows/safeequals.md), [SafeGreaterThan](../windows/safegreaterthan.md), [SafeGreaterThanEquals](../windows/safegreaterthanequals.md), [SafeLessThan](../windows/safelessthan.md), [SafeLessThanEquals](../windows/safelessthanequals.md), [ SafeNotEquals](../windows/safenotequals.md)|Compara dois números. Estas funções permitem comparar dois tipos diferentes de números sem alterar seus tipos.|  
|[SafeModulus](../windows/safemodulus.md)|Executa a operação de módulo em dois números.|  
|[SafeMultiply](../windows/safemultiply.md)|Multiplica dois números juntos e protege contra estouro.|  
|[SafeSubtract](../windows/safesubtract.md)|Subtrai dois números e protege contra estouro.|  
  
## <a name="related-sections"></a>Seções relacionadas  
  
|Seção|Descrição|  
|-------------|-----------------|  
|[Classe SafeInt](../windows/safeint-class.md)|O `SafeInt` classe.|  
|[Classe SafeIntException](../windows/safeintexception-class.md)|A classe de exceção específica para a biblioteca de SafeInt.|