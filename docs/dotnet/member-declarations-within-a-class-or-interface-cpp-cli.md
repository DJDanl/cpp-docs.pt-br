---
title: Declarações de membro em uma classe ou Interface (C + + / CLI) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- members, declaration syntax
- class members, declaration syntax
ms.assetid: 95d312a4-198b-46f0-b8f5-15253807c55e
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 80b872b4c614677c05b0d28b821d3a48255905c5
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46430625"
---
# <a name="member-declarations-within-a-class-or-interface-ccli"></a>Declarações de membro em uma classe ou uma interface (C++/CLI)

A declaração de propriedades e operadores extensivamente elaborada de extensões gerenciadas para C++ para Visual C++, ocultando os detalhes de implementação subjacentes que eram expostos no design extensões gerenciadas. Declarações de evento também foram modificadas.

Na categoria de alterações que ter nenhum suporte de extensões gerenciadas, construtores estáticos podem agora ser definida fora de linha (eles precisavam ser definidas embutidas dentro de Managed Extensions) e a noção de um construtor de delegação foi introduzido.

## <a name="in-this-section"></a>Nesta seção

[Declaração de propriedade](../dotnet/property-declaration.md)<br/>
Aborda as alterações às declarações de propriedade.

[Declaração do índice de propriedade](../dotnet/property-index-declaration.md)<br/>
Aborda as alterações às declarações de propriedade indexada.

[Delegados e eventos](../dotnet/delegates-and-events.md)<br/>
Aborda as alterações para a sintaxe para declarar delegados e eventos.

[Selando uma função virtual](../dotnet/sealing-a-virtual-function.md)<br/>
Aborda as alterações para a sintaxe para selando uma função.

[Operadores sobrecarregados](../dotnet/overloaded-operators.md)<br/>
Aborda as alterações para a sobrecarga de operador.

[Alterações em operadores de conversão](../dotnet/changes-to-conversion-operators.md)<br/>
Aborda as alterações para os operadores de conversão.

[Substituição explícita de um membro da interface](../dotnet/explicit-override-of-an-interface-member.md)<br/>
Aborda as alterações para o método de substituição explícita de um membro de interface.

[Funções virtuais particulares](../dotnet/private-virtual-functions.md)<br/>
Aborda as alterações da maneira que funções virtuais particulares são tratadas em classes derivadas.

[O vínculo integral de Static Const não é mais literal](../dotnet/static-const-int-linkage-is-no-longer-literal.md)<br/>
Aborda as alterações da maneira `static const` integrais membros são vinculados e como declarar explicitamente uma constante usando o novo `literal` palavra-chave.

## <a name="see-also"></a>Consulte também

[Primer de migração C++/CLI](../dotnet/cpp-cli-migration-primer.md)