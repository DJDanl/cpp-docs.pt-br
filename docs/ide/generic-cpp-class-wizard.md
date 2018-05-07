---
title: Assistente de classe C++ genérica | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-ide
ms.topic: conceptual
f1_keywords:
- vc.codewiz.class.generic
dev_langs:
- C++
helpviewer_keywords:
- Generic C++ Class Wizard [C++]
ms.assetid: aa95be9e-fc1b-45db-a11d-0d32c4929077
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 43e86a4047ef025f49dd01eda90f324623a90752
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="generic-c-class-wizard"></a>Assistente da Classe C++ Genérica
Adiciona uma classe C++ genérica para um projeto. A classe não herda de ATL ou do MFC.  
  
 **Nome de classe**  
 Define o nome da nova classe.  
  
 **arquivo. h**  
 Define o nome do arquivo de cabeçalho para a nova classe. Por padrão, esse nome é baseado no nome que você fornecer em **nome da classe**. Para salvar o arquivo de cabeçalho para o local de sua escolha, ou para acrescentar a declaração de classe para um arquivo existente, clique no botão de reticências (**...** ). Se você especificar um arquivo existente, quando você clica em **concluir**, o assistente solicita que você especifique se a declaração de classe deve ser anexada ao conteúdo do arquivo. Para acrescentar a declaração, clique em **Sim**; para voltar ao assistente e especifique outro nome de arquivo, clique em **não**.  
  
 **arquivo. cpp**  
 Define o nome do arquivo de implementação para a nova classe. Por padrão, esse nome é baseado no nome que você fornecer em **nome da classe**. Para salvar o arquivo de implementação para o local de sua escolha, ou para acrescentar a definição de classe para um arquivo existente, clique no botão de reticências (**...** ). Se você especificar um arquivo existente, quando você clica em **concluir**, o assistente solicita que você especifique se a definição de classe deve ser anexada ao conteúdo do arquivo. Para acrescentar a definição, clique em **Sim**; para voltar ao assistente e especifique outro nome de arquivo, clique em **não**.  
  
 **Classe base**  
 Define a classe base para a nova classe.  
  
 **Access**  
 Define o acesso a membros da classe base para a nova classe. Modificadores de acesso são palavras-chave que especificam o nível de acesso de outras classes para as funções de membro de classe. Para obter mais informações sobre como especificar o acesso, consulte [controle de acesso de membro](../cpp/member-access-control-cpp.md). Por padrão, o nível de acesso de classe é definido como `public`.  
  
-   `public`  
  
-   `protected`  
  
-   `private`  
  
-   **Padrão** (nenhum modificador de acesso é gerado).  
  
 **Destruidor virtual**  
 Especifica se o destruidor da classe virtual. Uso de um destruidor virtual ajuda a garantir que o destruidor correto é chamado quando instâncias de classes derivadas são excluídas.  
  
 **Embutido**  
 Gera o construtor da classe e a definição de classe como funções embutidas no arquivo de cabeçalho.  
  
 **Gerenciado**  
 Quando selecionada, adiciona um arquivo de cabeçalho e de classe gerenciado. Quando desmarcada, adiciona um arquivo de classe e cabeçalho nativo.  
  
## <a name="see-also"></a>Consulte também  
 [Adicionando uma classe do C++ genérica](../ide/adding-a-generic-cpp-class.md)