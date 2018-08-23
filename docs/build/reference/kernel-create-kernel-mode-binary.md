---
title: -kernel (Kernel de criar binário de modo) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- /kernel
- /kernel-
dev_langs:
- C++
ms.assetid: 6d7fdff0-c3d1-4b78-9367-4da588ce8b05
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 20ea3423acd19a70c5b7b759b9923b0132e04af0
ms.sourcegitcommit: e9ce38decc9f986edab5543de3464b11ebccb123
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/13/2018
ms.locfileid: "42573194"
---
# <a name="kernel-create-kernel-mode-binary"></a>/kernel (criar binário do modo kernel)
Cria um binário que pode ser executado no kernel do Windows.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
/kernel[-]  
```  
  
## <a name="arguments"></a>Arguments  
 **/kernel**  
 O código no projeto atual é compilado e vinculado usando um conjunto de regras da linguagem C++ que são específicos para o código que será executado no modo kernel.  
  
 **/kernel-**  
 O código no projeto atual é compilado e vinculado sem usar as regras da linguagem C++ que são específicas para o código que será executado no modo kernel.  
  
## <a name="remarks"></a>Comentários  
 Não há nenhum `#pragma` equivalente para controlar essa opção.  
  
 Especificando o **/kernel** opção informa ao compilador e vinculador arbitrar quais recursos de linguagem são permitidos no modo kernel e certificar-se de que você tem o poder expressivo suficiente para evitar instabilidade no tempo de execução que é exclusiva para modo de kernel C++. Isso é feito, proibindo o uso de recursos da linguagem C++ que causam interrupções no modo kernel e fornecendo avisos para recursos da linguagem C++ que são potencialmente interrupções, mas não podem ser desabilitados.  
  
 O **/kernel** opção aplica-se ao compilador e vinculador fases de um build e é definida no nível do projeto. Passe o **/kernel** alterne para indicar ao compilador que o binário resultante, após a vinculação, deve ser carregado no kernel do Windows. O compilador restringirá o espectro de recursos da linguagem C++ a um subconjunto que seja compatível com o kernel.  
  
 A tabela a seguir lista as alterações no comportamento do compilador quando **/kernel** for especificado.  
  
|Tipo de comportamento|**/kernel** comportamento|  
|-------------------|---------------------------|  
|Tratamento de exceções C++|Desabilitado. Todas as instâncias do `throw` e `try` palavras-chave emitem um erro do compilador (exceto para a especificação de exceção `throw()`). Não **/EH** as opções são compatíveis com **/kernel**, exceto para **/EH-**.|  
|RTTI|Desabilitado. Todas as instâncias de `dynamic_cast` e `typeid` palavras-chave para emitir um erro do compilador, a menos que `dynamic_cast` é usada estaticamente.|  
|`new` e `delete`|Você deve definir explicitamente o `new()` ou `delete()` operador; o compilador nem o tempo de execução, forneça uma definição default.|  
  
 Personalizar convenções de chamada, o [/GS](../../build/reference/gs-buffer-security-check.md) opção de compilação e todas as otimizações são permitidas quando você usa o **/kernel** opção. Inlining em grande parte não é afetada pelas **/kernel**, com a mesma semântica honrada pelo compilador. Se você quiser ter certeza de que o `__forceinline` qualificador inlining é cumprido, certifique-se de que o aviso [C4714](../../error-messages/compiler-warnings/compiler-warning-level-4-c4714.md) está habilitado para que você saiba quando uma determinada `__forceinline` função não está embutida.  
  
 Quando o compilador é passado a **/kernel** switch, ele predefine uma macro de pré-processador que é denominada `_KERNEL_MODE` e tem o valor **1**. Você pode usar isso para compilar condicionalmente o código com base em se o ambiente de execução está no modo de usuário ou kernel. Por exemplo, o código a seguir especifica que a classe deve estar em um segmento de memória não paginável, quando ele é compilado para execução em modo kernel.  
  
```cpp  
#ifdef _KERNEL_MODE  
#define NONPAGESECTION __declspec(code_seg("$kerneltext$"))  
#else  
#define NONPAGESECTION  
#endif  
  
class NONPAGESECTION MyNonPagedClass  
{  
   // ...
};  
```  
  
 Alguns seguintes combinações de arquitetura de destino e o **/arch** opção produzirá um erro quando eles são usados com **/kernel**:  
  
-   **/arch: {SSE&#124;SSE2&#124;AVX}** não têm suporte em x86. Somente **/arch:IA32** é compatível com **/kernel** em x86.  
  
-   **/arch: avx** não é compatível com **/kernel** em x64.  
  
 Compilando com **/kernel** também passa **/kernel** para o vinculador. Ela é como isso afeta o comportamento do vinculador:  
  
-   Vinculação incremental está desabilitada. Se você adicionar **/incremental** à linha de comando, o vinculador emite esse erro fatal:  
  
     **LINK: erro fatal LNK1295: '/ INCREMENTAL' não é compatível com ' / KERNEL' especificação; link sem '/ INCREMENTAL'**  
  
-   O vinculador inspeciona cada arquivo de objeto (ou qualquer membro do arquivo incluído de bibliotecas estáticas) para ver se ele pode foram compilado usando o **/kernel** opção, mas não era. Se todas as instâncias atenderem a esse critério, o vinculador vincula ainda com êxito mas pode emitir um aviso, conforme mostrado na tabela a seguir.  
  
    ||**/kernel** obj|**/kernel-** obj, MASM obj, ou cvtresed|Uma combinação de **/kernel** e **/kernel-** objetos|  
    |-|----------------------|-----------------------------------------------|-------------------------------------------------|  
    |**link /kernel**|Sim|Sim|Sim, com aviso LNK4257|  
    |**link**|Sim|Sim|Sim|  
  
     **Objeto de vinculação LNK4257 não compilado com /KERNEL; imagem não pode ser executada**  
  
 O **/kernel** opção e a **/driver** opção operar de forma independente e não afeta a outra.  
  
### <a name="to-set-the-kernel-compiler-option-in-visual-studio"></a>Para definir a opção do compilador /kernel no Visual Studio  
  
1.  Abra o **páginas de propriedade** caixa de diálogo para o projeto. Para obter mais informações, confira [Trabalhando com propriedades do projeto](../../ide/working-with-project-properties.md).  
  
2.  Selecione o **C/C++** pasta.  
  
3.  Selecione o **linha de comando** página de propriedades.  
  
4.  No **opções adicionais** caixa, adicione `/kernel` ou `/kernel-`.  
  
## <a name="see-also"></a>Consulte também  
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../../build/reference/setting-compiler-options.md)