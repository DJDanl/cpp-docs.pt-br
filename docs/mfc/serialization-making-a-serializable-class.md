---
title: "Serializa&#231;&#227;o: criando uma classe serializ&#225;vel | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "classes [C++], derivado"
  - "Classe CObject, derivando de classes que podem ser serializadas"
  - "construtores [C++], definindo sem argumentos"
  - "Macro DECLARE_SERIAL"
  - "construtor padrão"
  - "padrões [C++], construtor"
  - "Macro IMPLEMENT_SERIAL"
  - "sem construtor padrão"
  - "sem construtor de argumentos"
  - "classe que pode ser serializada"
  - "serialização [C++], classes que podem ser serializadas"
  - "Método Serialize, substituição"
  - "Macro VERSIONABLE_SCHEMA"
ms.assetid: 59a14d32-1cc8-4275-9829-99639beee27c
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Serializa&#231;&#227;o: criando uma classe serializ&#225;vel
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Cinco principais etapas são necessárias para fazer uma classe serializável.  São listados abaixo e explicados nas seguintes seções:  
  
1.  [Com sua classe de CObject](#_core_deriving_your_class_from_cobject) \(ou qualquer classe derivada de `CObject`\).  
  
2.  [Substituindo a função de membro serializar](#_core_overriding_the_serialize_member_function).  
  
3.  [Usando a macro de DECLARE\_SERIAL](#_core_using_the_declare_serial_macro) na declaração da classe.  
  
4.  [Definindo um construtor que não leve argumentos](#_core_defining_a_constructor_with_no_arguments).  
  
5.  [Usando a macro de IMPLEMENT\_SERIAL no arquivo de implementação](#_core_using_the_implement_serial_macro_in_the_implementation_file) para a sua classe.  
  
 Se você chamar `Serialize` diretamente em vez de por \>\> meio dos operadores \<\< de [CArchive](../mfc/reference/carchive-class.md), as três últimas etapas não são necessárias para a serialização.  
  
##  <a name="_core_deriving_your_class_from_cobject"></a> Com sua classe de CObject  
 O protocolo e a funcionalidade básicos de serialização são definidos na classe de `CObject` .  Com sua classe de `CObject` \(ou uma classe derivada de `CObject`\), conforme mostrado na seguinte declaração de classe `CPerson`, você ganha acesso ao protocolo de serialização e a funcionalidade de `CObject`.  
  
##  <a name="_core_overriding_the_serialize_member_function"></a> Substituindo a função de membro serializar  
 A função de membro de `Serialize` , que é definida na classe de `CObject` , é responsável para realmente serializar os dados necessários para capturar o estado atual de um objeto.  A função de `Serialize` tem um argumento de `CArchive` que usa o para ler e gravar os dados do objeto.  O objeto de [CArchive](../mfc/reference/carchive-class.md) tem uma função de membro, `IsStoring`, que indica se `Serialize` estiver armazenando \(gravando dados\) ou carregamento \(dados de leitura\).  Usando os resultados de `IsStoring` como a guia, você insere os dados do objeto no objeto de `CArchive` com o operador insert \(**\<\<**\) ou os dados extract com o operador de extração**\>\>**\(\).  
  
 Considere uma classe que é derivada de `CObject` e tem dois novos variáveis de membro, tipos de `CString` e **WORD**.  O seguinte fragmento de declaração de classe mostra os novos variáveis de membro e a declaração da função de membro substituída de `Serialize` :  
  
 [!code-cpp[NVC_MFCSerialization#1](../mfc/codesnippet/CPP/serialization-making-a-serializable-class_1.h)]  
  
#### Para substituir a função de membro serializar  
  
1.  Chamar sua versão da classe base de `Serialize` para garantir que a parte herdada do objeto é serializada.  
  
2.  Inserir ou extrair as variáveis de membros específicos da sua classe.  
  
     Os operadores de inserção e de extração interagem com a classe de arquivo morto para ler e gravar os dados.  O exemplo a seguir mostra como implementar `Serialize` para a classe de `CPerson` declarada anterior:  
  
     [!code-cpp[NVC_MFCSerialization#2](../mfc/codesnippet/CPP/serialization-making-a-serializable-class_2.cpp)]  
  
 Você também pode usar as funções de membro de [CArchive::Read](../Topic/CArchive::Read.md) e de [CArchive::Write](../Topic/CArchive::Write.md) para ler e gravar grandes quantidades de dados sem\-tipo.  
  
##  <a name="_core_using_the_declare_serial_macro"></a> Usando a macro de DECLARE\_SERIAL  
 A macro de `DECLARE_SERIAL` é necessário na declaração das classes que ofereça suporte à serialização, como mostrado a seguir:  
  
 [!code-cpp[NVC_MFCSerialization#3](../mfc/codesnippet/CPP/serialization-making-a-serializable-class_3.h)]  
  
##  <a name="_core_defining_a_constructor_with_no_arguments"></a> Definindo um construtor sem argumentos  
 O MFC requer um construtor padrão quando recriar seus objetos como desserializado \(carregado do disco\).  O processo de desserialização preencherá todas as variáveis do membro com os valores necessários para recriar o objeto.  
  
 Este construtor pode ser declarado, protegido, público ou particular.  Se você o fizer protegido ou particular, você ajuda a assegurar que será usado por funções de serialização.  O construtor deve colocar o objeto em um estado que permite que foi excluído se necessário.  
  
> [!NOTE]
>  Se você esquecer definir um construtor sem argumentos em uma classe que usa macros de `DECLARE_SERIAL` e de `IMPLEMENT_SERIAL` , você não terá nenhum aviso “disponível do compilador do construtor padrão” na linha onde a macro de `IMPLEMENT_SERIAL` é usado.  
  
##  <a name="_core_using_the_implement_serial_macro_in_the_implementation_file"></a> Usando a macro de IMPLEMENT\_SERIAL na implementação Arquivo  
 A macro de `IMPLEMENT_SERIAL` é usada para definir as várias funções necessárias quando você deve derivar uma classe de `CObject`serializável.  Você usa esta macro no arquivo de implementação .CPP \(\) para a sua classe.  Os primeiros dois argumentos para macro é o nome da classe e o nome da sua classe base imediata.  
  
 O terceiro argumento para esta macro é um número de esquema.  O número de esquema é essencialmente um número de versão para objetos da classe.  Use um inteiro maior que ou igual a 0 para o número de esquema. \(Não confunda esse número de esquema com a terminologia de base de dados\).  
  
 As verificações de código de serialização MFC o número do esquema ao ler objetos na memória.  Se o número do esquema do objeto no disco não corresponde ao número de esquema da classe na memória, a biblioteca lançará `CArchiveException`, impedindo que o programa lê uma versão incorreta de um objeto.  
  
 Se desejar que sua função de membro de `Serialize` para poder ler várias versões \- ou seja, arquivos gravados com versões diferentes do aplicativo — você pode usar o valor **VERSIONABLE\_SCHEMA** como um argumento para macro de `IMPLEMENT_SERIAL` .  Para obter informações de uso e um exemplo, consulte a função de membro de `GetObjectSchema` da classe `CArchive`.  
  
 O exemplo a seguir mostra como usar `IMPLEMENT_SERIAL` para uma classe, `CPerson`, que é derivada de `CObject`:  
  
 [!code-cpp[NVC_MFCSerialization#4](../mfc/codesnippet/CPP/serialization-making-a-serializable-class_4.cpp)]  
  
 Quando você tem uma classe serializável, é possível serializar objetos da classe, como descrito no artigo [Serialização: Serializando um objeto](../Topic/Serialization:%20Serializing%20an%20Object.md).  
  
## Consulte também  
 [Serialização](../Topic/Serialization%20in%20MFC.md)