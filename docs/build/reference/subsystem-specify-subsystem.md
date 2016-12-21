---
title: "/SUBSYSTEM (especificar subsistema) | Microsoft Docs"
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
  - "VC.Project.VCLinkerTool.SubSystem"
  - "VC.Project.VCLinkerTool.SubSystemVersion"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção de vinculador /SUBSYSTEM"
  - "opção de vinculador SUBSYSTEM"
  - "opção de vinculador -SUBSYSTEM"
  - "especificações de subsistema"
ms.assetid: d7b133cf-cf22-4da8-ab46-6552702c0b9b
caps.latest.revision: 25
caps.handback.revision: 25
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /SUBSYSTEM (especificar subsistema)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

```  
/SUBSYSTEM:{BOOT_APPLICATION|CONSOLE|EFI_APPLICATION|  
            EFI_BOOT_SERVICE_DRIVER|EFI_ROM|EFI_RUNTIME_DRIVER|NATIVE|  
            POSIX|WINDOWS)  
            [,major[.minor]]  
```  
  
 BOOT\_APPLICATION  
 Um aplicativo executado no ambiente de inicialização do Windows.  Para obter mais informações sobre os aplicativos de inicialização, consulte [Sobre o BCD](http://msdn.microsoft.com/library/windows/desktop/aa362639).  
  
 CONSOLE  
 Aplicativo de modo de caractere do Win32.  O sistema operacional fornece um console para aplicativos de console.  Se `main` ou `wmain` são definidos para o código nativo, `int main(array<String ^> ^)` está definido para o código gerenciado, ou você cria o aplicativo completamente usando `/clr:safe`, CONSOLE é o padrão.  
  
 Interface extensível de firmware  
 Os subsistemas de EFI\_\*.  Consulte a especificação de EFI para obter mais informações.  Por exemplo, consulte o site Intel.  A versão mínima e a versão da opção é 1,0.  
  
 NATIVE  
 Drivers do modo kernel do Windows NT.  Essa opção é reservada em geral para componentes do sistema do windows.  Se [\/DRIVER: WDM](../../build/reference/driver-windows-nt-kernel-mode-driver.md) for especificado, o NATIVO é o padrão.  
  
 POSIX  
 Aplicativo que executa com o subsistema de POSIX no Windows NT.  
  
 WINDOWS  
 O aplicativo não exigir um console, provavelmente como criar suas próprias o windows para interação com o usuário.  Se `WinMain` ou `wWinMain` são definidos para o código nativo, ou `WinMain(HISTANCE *, HINSTANCE *, char *, int)` ou `wWinMain(HINSTANCE *, HINSTANCE *, wchar_t *, int)` são definidos para o código gerenciado, WINDOWS é o padrão.  
  
 `Major` e `minor` \(opcional\)  
 Especificar a versão mínima necessária do subsistema.  Os argumentos são números decimais no intervalo de 0 a 65.535.  Consulte os comentários para obter mais informações.  Não há nenhum limite superior para números de versão.  
  
## Comentários  
 A opção \/SUBSYSTEM especifica o ambiente do executável.  
  
 A escolha do subsistema afeta o símbolo de ponto de entrada \(ou a função do ponto de entrada\) que o vinculador selecionará.  
  
 O valor mínimo e a opção `major` e números de versão opcionais de `minor` para os subsistemas são como se segue.  
  
|Subsistema|Mínimo|Padrão|  
|----------------|------------|------------|  
|BOOT\_APPLICATION|1.0|1.0|  
|CONSOLE|5,01 \(x86\) 5,02 \([!INCLUDE[vcprx64](../Token/vcprx64_md.md)]\) 6,02 \(BRAÇO\)|6,00 \(x86, [!INCLUDE[vcprx64](../Token/vcprx64_md.md)]\) 6,02 \(BRAÇO\)|  
|WINDOWS|5,01 \(x86\) 5,02 \([!INCLUDE[vcprx64](../Token/vcprx64_md.md)]\) 6,02 \(BRAÇO\)|6,00 \(x86, [!INCLUDE[vcprx64](../Token/vcprx64_md.md)]\) 6,02 \(BRAÇO\)|  
|NATIVE \(com DRIVER:WDM\)|1,00 \(x86\) 1,10 \([!INCLUDE[vcprx64](../Token/vcprx64_md.md)], BRAÇO\)|1,00 \(x86\) 1,10 \([!INCLUDE[vcprx64](../Token/vcprx64_md.md)], BRAÇO\)|  
|NATIVO \(sem \/DRIVER:WDM\)|4,00 \(x86\) 5,02 \([!INCLUDE[vcprx64](../Token/vcprx64_md.md)]\) 6,02 \(BRAÇO\)|4,00 \(x86\) 5,02 \([!INCLUDE[vcprx64](../Token/vcprx64_md.md)]\) 6,02 \(BRAÇO\)|  
|POSIX|1.0|19.90|  
|EFI\_APPLICATION, EFI\_BOOT\_SERVICE\_DRIVER, EFI\_ROM, EFI\_RUNTIME\_DRIVER|1.0|1.0|  
  
### Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedade** do projeto.  Para obter detalhes, consulte [Configurando as propriedades de projeto do Visual C\+\+](../../ide/working-with-project-properties.md).  
  
2.  Selecione a pasta do Vinculador.  
  
3.  Selecione a página de propriedades de **Sistema** .  
  
4.  Modifique a propriedade de `SubSystem` .  
  
### Para definir essa opção de vinculador por meio de programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.SubSystem%2A>.  
  
## Consulte também  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções de vinculador](../../build/reference/linker-options.md)