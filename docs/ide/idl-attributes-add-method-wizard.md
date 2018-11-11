---
title: Atributos IDL, Assistente de Adição de Método
ms.date: 11/04/2016
f1_keywords:
- vc.codewiz.method.idlattrib
helpviewer_keywords:
- Add Method Wizard [C++]
- IDL attributes, Add Method Wizard
ms.assetid: f80c3bc1-b515-4d6c-83ee-98c2c21ba902
ms.openlocfilehash: 073f821d7db0733c89c21ed4b2a85014aa151244
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50615781"
---
# <a name="idl-attributes-add-method-wizard"></a>Atributos IDL, Assistente de Adição de Método

Use esta página do Assistente de Adição de Método para especificar as configurações de linguagem IDL para o método.

- **id**

   Define a ID numérica que identifica o método. Confira [id](/windows/desktop/Midl/id) na *Referência de MIDL*.

   Essa caixa não está disponível para interfaces personalizadas nem para dispinterfaces MFC.

- **call_as**

   Especifica o nome de um método remoto para o qual esse método local pode ser mapeado. Confira [call_as](/windows/desktop/Midl/call-as) na *Referência de MIDL*.

   Não disponível para dispinterfaces MFC.

- **helpcontext**

   Especifica uma ID de contexto que permite ao usuário exibir informações sobre esse método no arquivo de Ajuda. Confira [helpcontext](/windows/desktop/Midl/helpcontext) na *Referência de MIDL*.

   Não disponível para dispinterfaces MFC.

- **helpstring**

   Especifica uma cadeia de caracteres que é usada para descrever o elemento ao qual ela se aplica. Por padrão, ela é definida como "method *Nome do método*". Confira [helpstring](/windows/desktop/Midl/helpstring) na *Referência de MIDL*.

   Não disponível para dispinterfaces MFC.

- **Atributos adicionais**

   Não disponível para dispinterfaces MFC.

   |Atributo|Descrição|
   |---------------|-----------------|
   |**hidden**|Indica que o método existe, mas que não deveria ser exibido em um navegador orientado ao usuário. Confira [hidden](/windows/desktop/Midl/hidden) na *Referência de MIDL*.|
   |**source**|Indica que um membro do método é uma origem de eventos. Confira [source](/windows/desktop/Midl/source) na *Referência de MIDL*.|
   |`local`|Especifica para o compilador MIDL que o método não é remoto. Confira [local](/windows/desktop/Midl/local) na *Referência de MIDL*.|
   |**restricted**|Especifica que o método não pode ser chamado arbitrariamente. Confira [restricted](/windows/desktop/Midl/restricted) na *Referência de MIDL*.|
   |**vararg**|Especifica que o método usa um número variável de argumentos. Para fazer isso, o último argumento precisa ser uma matriz segura do tipo **VARIANT** que contém todos os argumentos restantes. Confira [vararg](/windows/desktop/Midl/vararg) na *Referência de MIDL*.|

## <a name="see-also"></a>Consulte também

[Adicionando um método](../ide/adding-a-method-visual-cpp.md)<br>
[Assistente de Adição de Método](../ide/add-method-wizard.md)