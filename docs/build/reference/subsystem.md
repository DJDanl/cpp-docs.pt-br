---
title: -SUBSYSTEM | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- /subsystem
dev_langs:
- C++
helpviewer_keywords:
- /SUBSYSTEM editbin option
- -SUBSYSTEM editbin option
- SUBSYSTEM editbin option
ms.assetid: 515e4cdf-3cc4-4659-8764-1f2757b49215
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: c12df1a2166c9ef5a1af8a33a5764a8899909edb
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="subsystem"></a>/SUBSYSTEM
Especifica o ambiente de execução é necessária para a imagem executável.  
  
```  
/SUBSYSTEM:{BOOT_APPLICATION|CONSOLE|EFI_APPLICATION|  
        EFI_BOOT_SERVICE_DRIVER|EFI_ROM|EFI_RUNTIME_DRIVER|  
        NATIVE|POSIX|WINDOWS|WINDOWSCE}[,major[.minor]]  
```  
  
## <a name="remarks"></a>Comentários  
 Essa opção edita a imagem para indicar qual subsistema deve chamar o sistema operacional para execução.  
  
 Você pode especificar qualquer um dos seguintes subsistemas:  
  
 BOOT_APPLICATION  
 Um aplicativo que é executado no ambiente de inicialização do Windows. Para obter mais informações sobre aplicativos de inicialização, consulte [sobre o provedor WMI de BCD](http://msdn.microsoft.com/library/aa362639.aspx).  
  
 CONSOLE  
 Um aplicativo de modo de caractere do Windows. O sistema operacional fornece um console para aplicativos de console.  
  
 Imagem do Extensible Firmware Interface (EFI)  
 As opções de subsistema EFI descrevem imagens executáveis que são executados no ambiente de Interface de Firmware extensível. Esse ambiente normalmente é fornecido com o hardware e executa antes que o sistema operacional é carregado. As principais diferenças entre os tipos de imagem EFI são o local de memória que a imagem é carregada na e a ação executada quando a chamada para a imagem retorna. Uma imagem EFI_APPLICATION é descarregada quando o controle retorna. Um EFI_BOOT_SERVICE_DRIVER ou EFI_RUNTIME_DRIVER é descarregado somente se o controle retorna com um código de erro. Uma imagem EFI_ROM é executada na ROM. Para obter mais informações, consulte as especificações sobre o [Unified EFI Forum](http://www.uefi.org/) site.  
  
 NATIVO  
 Código que é executado sem um ambiente de subsistema — por exemplo, drivers de dispositivo de modo kernel e processos do sistema nativo. Essa opção normalmente é reservada para os recursos de sistema do Windows.  
  
 POSIX  
 Um aplicativo que é executado no subsistema POSIX em Windows.  
  
 WINDOWS  
 Um aplicativo que é executado no ambiente gráfico. Isso inclui aplicativos de área de trabalho e aplicativos do Windows UWP (plataforma Universal).  
  
 WINDOWSCE  
 O subsistema WINDOWSCE indica que o aplicativo é destinado para ser executado em um dispositivo que tenha uma versão do kernel do Windows CE. Versões do kernel incluem Pocket PC, Windows Mobile, Windows Phone 7, v 1.0-6.0R3 do Windows CE e Windows Embedded Compact 7.  
  
 Opcional `major` e `minor` valores especificam a versão mínima necessária do subsistema especificado:  
  
-   A parte de número inteiro do número de versão, a parte à esquerda da vírgula decimal — é representado por `major`.  
  
-   A parte fracionária do número de versão, a parte à direita da vírgula decimal — é representado por `minor`.  
  
-   Os valores de `major` e `minor` deve ser de 0 a 65.535.  
  
 A escolha de subsistema afeta o padrão de endereço para o programa inicial. Para obter mais informações, consulte [/ENTRY (símbolo de ponto de entrada)](../../build/reference/entry-entry-point-symbol.md), o vinculador /ENTRY:*função* opção.  
  
 Para obter mais informações, incluindo os valores mínimo e padrão para os números de versão primária e secundária para cada subsistema, consulte o [/SUBSYSTEM](../../build/reference/subsystem-specify-subsystem.md) opção de vinculador.  
  
## <a name="see-also"></a>Consulte também  
 [Opções de EDITBIN](../../build/reference/editbin-options.md)