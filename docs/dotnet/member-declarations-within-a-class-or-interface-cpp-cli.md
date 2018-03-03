---
title: "Declarações de membro em uma classe ou Interface (C + + CLI) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- members, declaration syntax
- class members, declaration syntax
ms.assetid: 95d312a4-198b-46f0-b8f5-15253807c55e
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 96a12f544babbf188c3718bcd49233472ad0d002
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="member-declarations-within-a-class-or-interface-ccli"></a>Declarações de membro em uma classe ou uma interface (C++/CLI)
A declaração de propriedades e operadores foi amplamente reformulada partir das extensões gerenciadas para C++ para Visual C++, ocultando os detalhes de implementação subjacente que estavam expostos no design do Managed Extensions. Declarações de evento também foram modificadas.  
  
 Na categoria de alterações que não há suporte das extensões gerenciadas, construtores estáticos pode ser definida fora de linha (eles precisavam ser definidas embutidas dentro das extensões gerenciadas) e a noção de um construtor delegado foi introduzido.  
  
## <a name="in-this-section"></a>Nesta seção  
 [Declaração de propriedade](../dotnet/property-declaration.md)  
 Discute alterações declarações de propriedade.  
  
 [Declaração do índice de propriedade](../dotnet/property-index-declaration.md)  
 Discute alterações declarações de propriedade indexada.  
  
 [Delegados e eventos](../dotnet/delegates-and-events.md)  
 Aborda as alterações para a sintaxe para declarar representantes e eventos.  
  
 [Selando uma função virtual](../dotnet/sealing-a-virtual-function.md)  
 Aborda as alterações com a sintaxe de fechamento de uma função.  
  
 [Operadores sobrecarregados](../dotnet/overloaded-operators.md)  
 Aborda as alterações para a sobrecarga de operador.  
  
 [Alterações em operadores de conversão](../dotnet/changes-to-conversion-operators.md)  
 Aborda as alterações para os operadores de conversão.  
  
 [Substituição explícita de um membro da interface](../dotnet/explicit-override-of-an-interface-member.md)  
 Aborda as alterações para o método para substituir explicitamente um membro de interface.  
  
 [Funções virtuais particulares](../dotnet/private-virtual-functions.md)  
 Aborda as alterações da forma funções virtuais particulares são tratadas em classes derivadas.  
  
 [O vínculo integral de Static Const não é mais literal](../dotnet/static-const-int-linkage-is-no-longer-literal.md)  
 Aborda as alterações na maneira como `static const` membros integrais são vinculados e como declarar explicitamente uma constante usando a nova `literal` palavra-chave.  
  
## <a name="see-also"></a>Consulte também  
 [Primer de migração C++/CLI](../dotnet/cpp-cli-migration-primer.md)