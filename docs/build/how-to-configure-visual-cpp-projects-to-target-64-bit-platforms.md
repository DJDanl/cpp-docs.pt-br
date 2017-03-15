---
title: "Como configurar projetos do Visual C++ para destinar plataformas de 64 bits | Microsoft Docs"
ms.custom: ""
ms.date: "12/14/2016"
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
  - "plataformas [C++], 64 bits"
  - "Configurando projetos de programação de 64 bits [C++]"
  - "configurações do projeto [C++]"
ms.assetid: 2b9ae001-df36-4750-83b2-982145d632ad
caps.latest.revision: 22
caps.handback.revision: 22
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Como configurar projetos do Visual C++ para destinar plataformas de 64 bits
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Você pode usar as configurações do projeto no Visual Studio para configurar aplicativos C\+\+ para plataformas de 64 bits. Você também pode migrar configurações de projeto Win32 em uma configuração de projeto de 64 bits.  
  
### Para configurar aplicativos C\+\+ para plataformas de 64 bits  
  
1.  Abra o projeto de C\+\+ que você deseja configurar.  
  
2.  Abra as páginas de propriedades para o projeto. Para obter mais informações, consulte [Como abrir páginas de propriedade do projeto](../misc/how-to-open-project-property-pages.md).  
  
    > [!NOTE]
    >  Para projetos do .NET, certifique\-se de que o **Propriedades de configuração** nó ou um de seus nós filho, está selecionado no **\< Projectname \> páginas de propriedade** caixa de diálogo; caso contrário, o **do Configuration Manager** permanece indisponível.  
  
3.  Escolha o **do Configuration Manager** para abrir o **do Configuration Manager** caixa de diálogo.  
  
4.  No **plataforma de solução ativa** lista suspensa, selecione o **\< Novo … \>** opção para abrir o **nova plataforma de solução** caixa de diálogo.  
  
5.  No **Digite ou selecione a nova plataforma** lista suspensa, selecione 64 bits de plataforma.  
  
    > [!NOTE]
    >  No **nova plataforma de solução** caixa de diálogo, você pode usar o **Copiar configurações de** opção para copiar as configurações de projeto existente para a nova configuração de projeto de 64 bits.  
  
6.  Escolha o botão **OK**. A plataforma que você selecionou na etapa anterior é exibido em **plataforma de solução ativa** no **do Configuration Manager** caixa de diálogo.  
  
7.  Escolha a **Fechar** no botão de **do Configuration Manager** caixa de diálogo caixa e, em seguida, escolha a **OK** no botão a **\< Projectname \> páginas de propriedade** caixa de diálogo.  
  
### Para copiar as configurações de projeto do Win32 para uma configuração de projeto de 64 bits  
  
-   Quando o **nova plataforma de solução** caixa de diálogo estiver aberta enquanto configura um projeto para o destino de uma plataforma de 64 bits, além de **Copiar configurações de** lista suspensa, selecione **Win32**. Essas configurações são atualizadas automaticamente no nível do projeto:  
  
    -   O [\/máquina](../build/reference/machine-specify-target-platform.md) opção de vinculador é definida como **\/MACHINE:X 64**.  
  
    -   **Registrar saída** está desativado. Para obter mais informações, consulte [Páginas de propriedade do vinculador](../ide/linker-property-pages.md).  
  
    -   **Ambiente de destino** é definido como **\/env x64**. Para obter mais informações, consulte [Páginas de propriedade MDL: geral](../ide/midl-property-pages-general.md).  
  
    -   **Validar parâmetros** é apagado e redefinido para o valor padrão. Para obter mais informações, consulte [Páginas de propriedade MIDL: avançado](../ide/midl-property-pages-advanced.md).  
  
    -   Se **formato informações de depuração** foi definido como **\/ZI** na configuração de projeto do Win32, em seguida, ele é definido como **\/Zi** na configuração do projeto de 64 bits. Para obter mais informações, consulte [\/Z7, \/Zi, \/ZI \(depurar formato de informações\)](../Topic/-Z7,%20-Zi,%20-ZI%20\(Debug%20Information%20Format\).md).  
  
    > [!NOTE]
    >  Nenhuma dessas propriedades de projeto são alteradas se elas são substituídas no nível de arquivo.  
  
## Consulte também  
 [Aplicativos de 64 bits](../Topic/64-bit%20Applications.md)   
 [Configurando programas para 64 bits](../build/configuring-programs-for-64-bit-visual-cpp.md)   
 [Depurar aplicativos de 64 bits](../Topic/Debug%2064-Bit%20Applications.md)