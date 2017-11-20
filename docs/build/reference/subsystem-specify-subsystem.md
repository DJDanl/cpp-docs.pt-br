---
title: -SUBSYSTEM (especificar subsistema) | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- /subsystem
- VC.Project.VCLinkerTool.SubSystem
- VC.Project.VCLinkerTool.SubSystemVersion
dev_langs: C++
helpviewer_keywords:
- /SUBSYSTEM linker option
- SUBSYSTEM linker option
- -SUBSYSTEM linker option
- subsystem specifications
ms.assetid: d7b133cf-cf22-4da8-ab46-6552702c0b9b
caps.latest.revision: "25"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: bfdb54ece1669a2e3630fecad2d23ee55c2ac823
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="subsystem-specify-subsystem"></a>/SUBSYSTEM (especificar subsistema)
```  
/SUBSYSTEM:{BOOT_APPLICATION|CONSOLE|EFI_APPLICATION|  
            EFI_BOOT_SERVICE_DRIVER|EFI_ROM|EFI_RUNTIME_DRIVER|NATIVE|  
            POSIX|WINDOWS)  
            [,major[.minor]]  
```  
  
 BOOT_APPLICATION  
 Um aplicativo que é executado no ambiente de inicialização do Windows. Para obter mais informações sobre aplicativos de inicialização, consulte [sobre BCD](http://msdn.microsoft.com/library/windows/desktop/aa362639).  
  
 CONSOLE  
 Aplicativo de modo caractere Win32. O sistema operacional fornece um console para aplicativos de console. Se `main` ou `wmain` está definido para código nativo, `int main(array<String ^> ^)` está definido para código gerenciado, ou criar o aplicativo completamente usando `/clr:safe`, CONSOLE é o padrão.  
  
 Interface de Firmware extensível  
 Os subsistemas de EFI_ *. Consulte a especificação de EFI para obter mais informações. Por exemplo, consulte o site da Intel. A versão mínima de versão e o padrão é 1.0.  
  
 NATIVO  
 Drivers do modo kernel para Windows NT. Essa opção normalmente é reservada para os componentes de sistema do Windows. Se [/driver: WDM](../../build/reference/driver-windows-nt-kernel-mode-driver.md) for especificado, nativo é o padrão.  
  
 POSIX  
 Aplicativo que é executado com o subsistema POSIX em Windows NT.  
  
 WINDOWS  
 Aplicativo não exigir um console, provavelmente porque cria suas próprias janelas para interação com o usuário. Se `WinMain` ou `wWinMain` está definido para código nativo, ou `WinMain(HISTANCE *, HINSTANCE *, char *, int)` ou `wWinMain(HINSTANCE *, HINSTANCE *, wchar_t *, int)` é definido para código gerenciado, o WINDOWS é o padrão.  
  
 `Major`e `minor` (opcional)  
 Especifique a versão mínima necessária do subsistema. Os argumentos são números decimais no intervalo de 0 a 65.535. Consulte os Comentários para obter mais informações. Não há nenhum limites superiores para números de versão.  
  
## <a name="remarks"></a>Comentários  
 A opção /SUBSYSTEM Especifica o ambiente para o executável.  
  
 A escolha de subsistema afeta o símbolo de ponto de entrada (ou a função de ponto de entrada) que seleciona o vinculador.  
  
 O padrão e o mínimo opcional `major` e `minor` números de versão para os subsistemas são da seguinte maneira.  
  
|Subsistema|Mínimo|Padrão|  
|---------------|-------------|-------------|  
|BOOT_APPLICATION|1.0|1.0|  
|CONSOLE|5.01 (x86) 5.02 ([!INCLUDE[vcprx64](../../assembler/inline/includes/vcprx64_md.md)]) 6.02 (ARM)|6.00 (x86, [!INCLUDE[vcprx64](../../assembler/inline/includes/vcprx64_md.md)]) 6.02 (ARM)|  
|WINDOWS|5.01 (x86) 5.02 ([!INCLUDE[vcprx64](../../assembler/inline/includes/vcprx64_md.md)]) 6.02 (ARM)|6.00 (x86, [!INCLUDE[vcprx64](../../assembler/inline/includes/vcprx64_md.md)]) 6.02 (ARM)|  
|NATIVO (com o DRIVER: WDM)|1,00 (x86) 1.10 ([!INCLUDE[vcprx64](../../assembler/inline/includes/vcprx64_md.md)], ARM)|1,00 (x86) 1.10 ([!INCLUDE[vcprx64](../../assembler/inline/includes/vcprx64_md.md)], ARM)|  
|NATIVO (sem /driver: WDM)|4.00 (x86) 5.02 ([!INCLUDE[vcprx64](../../assembler/inline/includes/vcprx64_md.md)]) 6.02 (ARM)|4.00 (x86) 5.02 ([!INCLUDE[vcprx64](../../assembler/inline/includes/vcprx64_md.md)]) 6.02 (ARM)|  
|POSIX|1.0|19.90|  
|EFI_APPLICATION, EFI_BOOT_SERVICE_DRIVER, EFI_ROM, EFI_RUNTIME_DRIVER|1.0|1.0|  
  
### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [configuração Visual C++ Project Properties](../../ide/working-with-project-properties.md).  
  
2.  Selecione a pasta do vinculador.  
  
3.  Selecione o **sistema** página de propriedades.  
  
4.  Modificar o `SubSystem` propriedade.  
  
### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.SubSystem%2A>.  
  
## <a name="see-also"></a>Consulte também  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções do vinculador](../../build/reference/linker-options.md)