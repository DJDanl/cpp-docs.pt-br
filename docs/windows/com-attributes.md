---
title: Atributos COM | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: language-reference
dev_langs: C++
helpviewer_keywords:
- attributes [C++], reference topics
- attributes [COM]
- COM, attributes
ms.assetid: 52a5dd70-e8be-4bba-afd6-daf90fe689a0
caps.latest.revision: "9"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: f9cd3657426a2a51a582ab695376287a3e975056
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="com-attributes"></a>Atributos COM
Os atributos COM injetar código para oferecer suporte a várias áreas de desenvolvimento COM e desenvolvimento de tempo de execução de linguagem comum do .NET Framework. Esses variam de áreas de implementação de interface personalizada e suporte às interfaces existentes para dar suporte a eventos, métodos e propriedades de estoque. Além disso, o suporte foi encontrado para composição e implementação de controle ActiveX.  
  
|Atributo|Descrição|  
|---------------|-----------------|  
|[aggregatable](../windows/aggregatable.md)|Indica se um controle pode ser agregado por outro controle.|  
|[aggregates](../windows/aggregates.md)|Indica que um controle agrega a classe de destino.|  
|[coclass](../windows/coclass.md)|Cria um objeto COM, que pode implementar uma interface COM.|  
|[com_interface_entry](../windows/com-interface-entry-cpp.md)|Adiciona uma entrada de interface para um mapa de COM.|  
|[implements_category](../windows/implements-category.md)|Especifica as categorias de componente implementado para a classe.|  
|[progid](../windows/progid.md)|Define o ProgID de um controle.|  
|[rdx](../windows/rdx.md)|Cria ou modifica uma chave do registro.|  
|[registration_script](../windows/registration-script.md)|Executa o script de registro especificado.|  
|[requires_category](../windows/requires-category.md)|Especifica as categorias de componente necessário para a classe.|  
|[support_error_info](../windows/support-error-info.md)|Dá suporte a relatórios de erros para o objeto de destino.|  
|[synchronize](../windows/synchronize.md)|Sincroniza o acesso a um método.|  
|[Threading](../windows/threading-cpp.md)|Especifica o modelo de threading para um objeto COM.|  
|[vi_progid](../windows/vi-progid.md)|Define uma versão de ProgID para um controle.|  
  
## <a name="see-also"></a>Consulte também  
 [Atributos por grupo](../windows/attributes-by-group.md)