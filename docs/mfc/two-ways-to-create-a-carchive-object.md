---
title: "Duas maneiras de criar um objeto CArchive | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "CArchive"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe CArchive, fechando objetos CArchive"
  - "Classe CArchive, construtor"
  - "Objetos CArchive"
  - "Objetos CArchive, fechamento"
  - "armazenamento de dados [C++], Classe CArchive"
  - "E/S [MFC], criando objetos CArchive"
  - "serialização [C++], Classe CArchive"
  - "armazenamento [C++], Classe CArchive"
ms.assetid: aefa28ce-b55c-40dc-9e42-5f038030985d
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Duas maneiras de criar um objeto CArchive
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Há duas maneiras de criar um objeto de `CArchive` :  
  
-   [Implícita criação de um objeto de CArchive pela estrutura](#_core_implicit_creation_of_a_carchive_object_via_the_framework)  
  
-   [Explícita criação de um objeto de CArchive](#_core_explicit_creation_of_a_carchive_object)  
  
##  <a name="_core_implicit_creation_of_a_carchive_object_via_the_framework"></a> Implícita criação de um objeto de CArchive pela estrutura  
 Mais comum, e o modo mais fácil, são deixar a estrutura criar um objeto de `CArchive` para o documento em nome de salvamento, de salvar como, e os comandos abertos no menu arquivo.  
  
 Eis como a estrutura faz quando o usuário do aplicativo emite a salvar como o comando de menu arquivo:  
  
1.  Mostra a caixa de diálogo de **Salvar como** e obtém o nome de arquivo de usuário.  
  
2.  Abre o arquivo chamado pelo usuário como um objeto de `CFile` .  
  
3.  Cria um objeto de `CArchive` que aponta para este `CFile` objeto.  Na criação do objeto de `CArchive` , a estrutura define o modo “para armazenar” \(a gravação, serializa\), em vez de “carregamento” \(a leitura, e\).  
  
4.  Chama a função de `Serialize` definida no seu **CDocument**\- classe derivada, passando a uma referência ao objeto de `CArchive` .  
  
 A função de `Serialize` do documento depois grava dados no objeto de `CArchive` , conforme explicado em.  No retorno da função de `Serialize` , a estrutura destrói o objeto de `CArchive` e o objeto de `CFile` .  
  
 Portanto, se você deixar a estrutura criar o objeto de `CArchive` para o documento, tudo que você tem que fazer é implementar a função de `Serialize` de documento que grava e ler a e de arquivo morto.  Você também tem que implementar `Serialize` para qualquer `CObject`\- objetos derivados da função de `Serialize` do documento serializa por sua vez direta ou indiretamente.  
  
##  <a name="_core_explicit_creation_of_a_carchive_object"></a> Explícita criação de um objeto de CArchive  
 Além de serializar um documento na estrutura, existem outras ocasiões em que você pode precisar de um objeto de `CArchive` .  Por exemplo, talvez você queira serializar dados para e da área de transferência, representado por um objeto de `CSharedFile` .  Ou, você pode usar uma interface do usuário para salvar um arquivo que é diferente do oferecido pela estrutura.  Nesse caso, você pode criar explicitamente um objeto de `CArchive` .  Você faz isso a mesma forma que faz a estrutura, usando o procedimento a seguir.  
  
#### Para criar explicitamente um objeto de CArchive  
  
1.  Construir um objeto de `CFile` ou um objeto derivado de `CFile`.  
  
2.  Passe o objeto de `CFile` para o construtor para `CArchive`, conforme mostrado no seguinte exemplo:  
  
     [!code-cpp[NVC_MFCSerialization#5](../mfc/codesnippet/CPP/two-ways-to-create-a-carchive-object_1.cpp)]  
  
     O segundo argumento para o construtor de `CArchive` é um valor enumerado que especifica se o arquivo morto será usado para armazenar ou carregando dados para ou do arquivo.  A função de `Serialize` de um objeto verifica esse estado chamando a função de `IsStoring` para o objeto de arquivo morto.  
  
 Quando você armazenar é concluído ou carregando dados para ou de `CArchive` objeto, feche\-o.  Embora os objetos de `CArchive` \(e\) `CFile`fechem automaticamente o arquivo morto \(\) e o arquivo, é uma prática recomendada a explicitamente é feito desde que facilita a recuperação de erros.  Para obter mais informações sobre como tratar erros, consulte o artigo [Exceções: Capturando e excluindo exceções](../mfc/exceptions-catching-and-deleting-exceptions.md).  
  
#### Para fechar o objeto de CArchive  
  
1.  O exemplo a seguir ilustra como fechar o objeto de `CArchive` :  
  
     [!code-cpp[NVC_MFCSerialization#6](../mfc/codesnippet/CPP/two-ways-to-create-a-carchive-object_2.cpp)]  
  
## Consulte também  
 [Serialização: serializando um objeto](../Topic/Serialization:%20Serializing%20an%20Object.md)