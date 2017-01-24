---
title: "Acessando informa&#231;&#245;es da classe runtime | Microsoft Docs"
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
  - "classes [C++], informações da classe runtime"
  - "Classe CObject, acessando informações da classe runtime"
  - "Classe CObject, e RTTI"
  - "Classe CObject, usando o método IsKindOf"
  - "Classe CObject, usando a macro RUNTIME_CLASS"
  - "Método método IsKindOf"
  - "Opção de compilador  (RTTI)"
  - "tempo de execução"
  - "tempo de execução, informações de classe"
  - "classe runtime"
  - "classe runtime, acessando informações"
  - "Macro RUNTIME_CLASS"
  - "Macro RUNTIME_CLASS, usando"
ms.assetid: 3445a9af-0bd6-4496-95c3-aa59b964570b
caps.latest.revision: 11
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Acessando informa&#231;&#245;es da classe runtime
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este artigo explica como acessar em tempo de execução informações sobre a classe de um objeto.  
  
> [!NOTE]
>  MFC O não usa o suporte de [Informações de tipo de tempo de execução](../Topic/Run-Time%20Type%20Information.md) \(\) RTTI introduzido no Visual C\+\+ 4.0.  
  
 Se você derivadas a sua classe de [CObject](../Topic/CObject%20Class.md) e usou o \_**DYNAMIC** e `IMPLEMENT_DYNAMIC`, `DECLARE_DYNCREATE` e `IMPLEMENT_DYNCREATE`de **DECLARE**, ou macros de `DECLARE_SERIAL` e de `IMPLEMENT_SERIAL` explicados no artigo [Com uma classe de CObject](../mfc/deriving-a-class-from-cobject.md), a classe de `CObject` tem a capacidade de determinar em tempo de execução a classe precisa de um objeto.  
  
 Essa capacidade é mais útil quando a verificação de tipo adicional de argumentos de função é necessária e quando você deve escrever o código do objetivo especial com base na classe de um objeto.  No entanto, essa prática recomendada é normalmente porque não duplica a funcionalidade de funções virtuais.  
  
 A função de membro `IsKindOf` de `CObject` pode ser usada para determinar se um determinado objeto pertence a uma classe especificada ou se é derivado de uma classe específica.  O argumento para `IsKindOf` é um objeto de `CRuntimeClass` , que você pode obter com a macro de `RUNTIME_CLASS` com o nome da classe.  
  
### Para usar a macro de RUNTIME\_CLASS  
  
1.  Use `RUNTIME_CLASS` com o nome da classe, conforme mostrado aqui para a classe `CObject`:  
  
     [!code-cpp[NVC_MFCCObjectSample#4](../mfc/codesnippet/CPP/accessing-run-time-class-information_1.cpp)]  
  
 Você precisará raramente de acessar diretamente o objeto da classe de tempo de execução.  Uso mais comum é passe o objeto da classe de tempo de execução à função de `IsKindOf` , conforme mostrado no procedimento a seguir.  Testes de função de `IsKindOf` um objeto para verificar se pertence a uma classe específica.  
  
#### Para usar a função de IsKindOf  
  
1.  Verifique a classe que tem o suporte da classe de tempo de execução.  Isto é, a classe deve ter sido derivada direta ou indiretamente de `CObject` e usou o \_**DYNAMIC** e `IMPLEMENT_DYNAMIC`, `DECLARE_DYNCREATE` e `IMPLEMENT_DYNCREATE`de **DECLARE**, ou macros de `DECLARE_SERIAL` e de `IMPLEMENT_SERIAL` explicados no artigo [Com uma classe de CObject](../mfc/deriving-a-class-from-cobject.md).  
  
2.  Chame a função de membro de `IsKindOf` para objetos dessa classe, usando a macro de `RUNTIME_CLASS` para gerar o argumento de `CRuntimeClass` , como mostrado a seguir:  
  
     [!code-cpp[NVC_MFCCObjectSample#2](../mfc/codesnippet/CPP/accessing-run-time-class-information_2.h)]  
  
     [!code-cpp[NVC_MFCCObjectSample#5](../mfc/codesnippet/CPP/accessing-run-time-class-information_3.cpp)]  
  
    > [!NOTE]
    >  IsKindOf retorna **Verdadeiro** se o objeto for um membro da classe especificada ou de uma classe derivada da classe especificada.  `IsKindOf` não da suporte a herança múltipla ou classes base virtuais, embora você possa usar a herança múltipla para suas classes derivadas do Microsoft se necessário.  
  
 Um uso de informações da classe de tempo de execução estiver em criação dinâmico de objetos.  Esse processo é discutido no artigo [Criação do objeto dinâmico](../Topic/Dynamic%20Object%20Creation.md).  
  
 Para obter informações mais detalhadas sobre a serialização e de informações da classe de tempo de execução, consulte os artigos [Arquivos em MFC](../mfc/files-in-mfc.md) e [Serialização](../Topic/Serialization%20in%20MFC.md).  
  
## Consulte também  
 [Usando CObject](../mfc/using-cobject.md)