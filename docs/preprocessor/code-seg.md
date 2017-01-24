---
title: "code_seg | Microsoft Docs"
ms.custom: ""
ms.date: "12/15/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "code_seg_CPP"
  - "vc-pragma.code_seg"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "code_seg (pragma)"
  - "pragmas, code_seg"
ms.assetid: bf4faac1-a511-46a6-8d9e-456851d97d56
caps.latest.revision: 9
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# code_seg
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Especifica o segmento de texto onde as funções são armazenadas no arquivo .obj.  
  
## Sintaxe  
  
```  
#pragma code_seg( [ [ { push | pop }, ] [ identifier, ] ] [ "segment-name" [, "segment-class" ] )  
```  
  
## Comentários  
 A diretiva de pragma `code_seg` não controla o posicionamento do código de objeto gerado por modelos instanciados, nem do código gerado implicitamente pelo compilador \(por exemplo, funções membro especiais\).  É recomendável usar o atributo [\_\_declspec\(code\_seg\(...\)\)](../cpp/code-seg-declspec.md) no lugar, pois ele proporciona controle sobre o posicionamento de todo o código de objeto.  Isso inclui o código gerado pelo compilador.  
  
 Um *segmento* em um arquivo .obj é um bloco de dados nomeado que é carregado na memória como uma unidade.  Um *segmento de texto* é um segmento que contém código executável.  Neste artigo, os termos *segmento* e *seção* são usados alternadamente.  
  
 A diretiva de pragma `code_seg` informa o compilador para colocar todos os códigos de objeto subsequentes da unidade de tradução em um segmento de texto denominado `segment-name`.  Por padrão, o segmento de texto usado para funções em um arquivo .obj é denominado .text.  
  
 Uma diretiva de pragma `code_seg` sem parâmetros redefine o nome do segmento do texto do código de objeto subsequente para .text.  
  
 **Push** \(opcional\)  
 Coloca um registro na pilha interna do compilador.  Um **push** pode ter um `identifier` e `segment-name`.  
  
 **pop** \(opcional\)  
 Remove um registro do topo da pilha interna do compilador.  
  
 `identifier` \(opcional\)  
 Quando usado com **push**, atribui um nome ao registro na pilha interna do compilador.  Quando usado com **pop**, elimina registros da pilha interna até que `identifier` seja removido; se `identifier` não for localizado na pilha interna, nada será exibido.  
  
 `identifier` habilita vários registros a serem exibidos com apenas um comando **pop**.  
  
 "`segment-name`" \(opcional\)  
 O nome de um segmento.  Quando usado com **pop**, a pilha é exibida e `segment-name` torna\-se o nome ativo do segmento de texto.  
  
 "`segment-class`" \(opcional\)  
 Ignorado, mas incluído para compatibilidade com versões C\+\+ anteriores à versão 2.0.  
  
 Você pode usar o aplicativo [DUMPBIN.EXE](../build/reference/dumpbin-command-line.md) para exibir arquivos .obj.  As versões de DUMPBIN para cada arquitetura de destino com suporte estão incluídas em [!INCLUDE[vsprvs](../assembler/masm/includes/vsprvs_md.md)].  
  
## Exemplo  
 Este exemplo mostra como usar a diretiva de pragma `code_seg` para controlar onde o código de objeto será colocado:  
  
```  
// pragma_directive_code_seg.cpp  
void func1() {                  // stored in .text  
}  
  
#pragma code_seg(".my_data1")  
void func2() {                  // stored in my_data1  
}  
  
#pragma code_seg(push, r1, ".my_data2")  
void func3() {                  // stored in my_data2  
}  
  
#pragma code_seg(pop, r1)      // stored in my_data1  
void func4() {  
}  
  
int main() {  
}  
```  
  
 Para obter uma lista de nomes que não devem ser usados para criar uma seção, consulte [\/SECTION](../build/reference/section-specify-section-attributes.md).  
  
 Você também pode especificar seções para dados inicializados \([data\_seg](../preprocessor/data-seg.md)\), dados não inicializados \([bss\_seg](../preprocessor/bss-seg.md)\) e variáveis constantes \([const\_seg](../preprocessor/const-seg.md)\).  
  
## Consulte também  
 [code\_seg \(\_\_declspec\)](../cpp/code-seg-declspec.md)   
 [Diretivas Pragma e a palavra\-chave \_\_Pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)