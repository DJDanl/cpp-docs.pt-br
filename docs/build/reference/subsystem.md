---
title: "/SUBSYSTEM | Microsoft Docs"
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
  - "/subsystem"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção /SUBSYSTEM (editbin)"
  - "opção editbin SUBSYSTEM"
  - "opção editbin -SUBSYSTEM"
ms.assetid: 515e4cdf-3cc4-4659-8764-1f2757b49215
caps.latest.revision: 12
caps.handback.revision: 12
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /SUBSYSTEM
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Especifica o ambiente de execução que é exigido pela imagem executável.  
  
```  
/SUBSYSTEM:{BOOT_APPLICATION|CONSOLE|EFI_APPLICATION|  
        EFI_BOOT_SERVICE_DRIVER|EFI_ROM|EFI_RUNTIME_DRIVER|  
        NATIVE|POSIX|WINDOWS|WINDOWSCE}[,major[.minor]]  
```  
  
## Comentários  
 Essa opção edita a imagem para indicar qual subsistema deve chamar o sistema operacional para execução.  
  
 Você pode especificar qualquer um dos seguintes subsistemas:  
  
 BOOT\_APPLICATION  
 Um aplicativo executado no ambiente de inicialização do Windows.  Para obter mais informações sobre aplicativos de inicialização, consulte [sobre o provedor WMI BCD](http://msdn.microsoft.com/library/aa362639.aspx).  
  
 CONSOLE  
 Um aplicativo de modo de caracteres do Windows.  O sistema operacional fornece um console para aplicativos de console.  
  
 Imagem do Extensible Firmware Interface \(EFI\)  
 As opções de subsistema EFI descrevem imagens executáveis que são executados no ambiente de Interface de Firmware extensível.  Esse ambiente normalmente é fornecido com o hardware e executa antes que o sistema operacional é carregado.  As principais diferenças entre os tipos de imagem EFI são o local da memória que a imagem é carregada na e a ação é executada quando retorna a chamada para a imagem.  Uma imagem EFI\_APPLICATION é descarregada quando o controle retorna.  Um EFI\_BOOT\_SERVICE\_DRIVER ou EFI\_RUNTIME\_DRIVER é descarregado somente se o controle retorna com um código de erro.  Uma imagem EFI\_ROM é executada a partir de ROM.  Para obter mais informações, consulte as especificações sobre o [Unified EFI Forum](http://www.uefi.org/) site.  
  
 NATIVO  
 Código que é executado sem um ambiente de subsistema — por exemplo, drivers de dispositivo de modo kernel e processos de sistema nativo.  Essa opção geralmente é reservada para recursos de sistema do Windows.  
  
 POSIX  
 Um aplicativo que é executado no subsistema POSIX no Windows.  
  
 WINDOWS  
 Um aplicativo que é executado no ambiente gráfico do Windows.  Isso inclui aplicativos de área de trabalho e aplicativos da Windows Store.  
  
 WINDOWSCE  
 O subsistema WINDOWSCE indica que o aplicativo deve executar em um dispositivo que tenha uma versão do kernel do Windows CE.  Versões de kernel incluem Pocket PC, Windows Mobile, Windows Phone 7, Windows CE v 1.0\-6.0R3 e Windows Embedded Compact 7.  
  
 Opcional `major` e `minor` valores especificam a versão mínima necessária do subsistema especificado:  
  
-   A parte de número inteiro do número da versão — a parte à esquerda da vírgula decimal — é representado por `major`.  
  
-   A parte fracionária do número da versão — a parte à direita do ponto decimal — é representado por `minor`.  
  
-   Os valores de `major` e `minor` deve ser de 0 a 65.535.  
  
 A escolha do subsistema afeta o padrão de endereço para o programa inicial.  Para obter mais informações, consulte [\/ENTRY \(símbolo do ponto de entrada\)](../../build/reference/entry-entry-point-symbol.md), o vinculador \/ENTRY:*função* opção.  
  
 Para obter mais informações, incluindo os valores mínimo e padrão para os números de versão principal e secundária para cada subsistema, consulte o [\/SUBSYSTEM](../../build/reference/subsystem-specify-subsystem.md) opção de vinculador.  
  
## Consulte também  
 [Opções EDITBIN](../../build/reference/editbin-options.md)